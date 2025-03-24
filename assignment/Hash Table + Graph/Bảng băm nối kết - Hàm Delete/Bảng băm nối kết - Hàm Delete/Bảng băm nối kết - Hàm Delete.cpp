
#include <iostream>
#include <string>

#define LOAD 0.7
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Node {
    Hocsinh data;
    Node* next;
};

struct List {
    Node* head, * tail;
};

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List* table;
};
void Init(List& L)
{
    L.head = L.tail = NULL;
}
void CreateHashtable(Hashtable& hashtable, int m)
{
    hashtable.M = m;
    hashtable.n = 0;
    hashtable.table = new List[m];
    for (int i = 0; i < m; i++)
    {
        Init(hashtable.table[i]);
    }
}void Input(Hocsinh& hs)
{
    cin >> hs.Maso;
    getline(cin>>ws, hs.Hoten);
    cin >> hs.Gioitinh;
    cin >> hs.Namsinh;
    cin >> hs.TBK;
}
void AddTail(List& L, Hocsinh hs)
{
    Node* p = new Node;
    p->data = hs;
    p->next = NULL;
    if (L.head == NULL)
    {
        L.head = L.tail = p;
    }
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}
void deleteHead(List& L)
{
    if (L.head == NULL) return;
    if (L.head == L.tail)
    {
        L.head = L.tail = NULL;
    }
    else
        L.head = L.head->next;
}
void deletail(List& L)
{
    if (L.head == NULL) return;
    if (L.head == L.tail)
    {
        delete L.head;
        L.head = L.tail = NULL;
    }
    else
    {
        Node* p = L.head;
        while (p->next != L.tail)
        {
            p = p->next;
        }
        delete L.tail;
        L.tail = p;
        L.tail->next = NULL;
    }
}
Node* searchEle(List L, int x)
{
    Node* p = L.head;
    while (p != NULL)
    {
        if (p->data.Maso == x) return p;
        p = p->next;
    }
    return NULL;
}
void deleteNode(List& L, int x)
{
    Node* p = L.head;
    Node* k = searchEle(L, x);
    if (k == NULL) return;
    else
    {
        if (k == L.head) deleteHead(L);
        else
            if (k == L.tail) deletail(L);
            else
            {
                while (p->next != k)
                    p = p->next;
                p->next = k->next;
                delete k;

            }
    }

}
void PrintHashtable(Hashtable& hashtable)
{
    for (int i = 0; i < hashtable.M; i++)
    {
        Node* hs = hashtable.table[i].head;
        while (hs)
        {
            cout << '[' << hs->data.Maso << ",  " << hs->data.Hoten << "  , " << hs->data.Gioitinh << ", " << hs->data.Namsinh << ", " << hs->data.TBK << "] ";
            hs = hs->next;
        }
        cout << endl;
    }
}
void DeleteHashtable(Hashtable& hashtable)
{
    for (int i = 0; i < hashtable.M; i++) {
        Node* current = hashtable.table[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        hashtable.table[i].head = NULL;
        hashtable.table[i].tail = NULL;
    }

    delete[] hashtable.table;
    hashtable.table = NULL;
    hashtable.n = 0;
    hashtable.M = 0;
}
bool Delete(Hashtable& hashtable, int maso) {
   
    int index = maso % hashtable.M;
    Node* p = searchEle(hashtable.table[index-1],maso);
    if (p)
    {
        deleteNode(hashtable.table[index-1], maso);
        hashtable.n--;
        return true;
    }
    return false; 
}
int main()
{
    Hashtable hashtable;

    int m, n, k;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        cin >> k;
        hashtable.n += k;
        for (int j = 0; j < k; j++) {
            Input(hs);
            AddTail(hashtable.table[i], hs);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;

        if (Delete(hashtable, k) == 0)
            cout << "KHONG XOA DUOC\n";
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
