
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
int Hash(Hashtable H, int maso) {
    return maso % H.M;
}
void Input(Hocsinh& x) {
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void Init(List& L)
{
    L.head = L.tail = NULL;
}
void CreateHashtable(Hashtable& hashtable, int  m)
{
    hashtable.M = m;
    hashtable.n = 0;
    hashtable.table = new List[m];
    for (int i = 0; i < m; i++)
    {
        Init(hashtable.table[i]);
    }
}
void addtail(List& L, Hocsinh hs)
{
    Node* p = new Node;
    p->data = hs;
    if (L.head == NULL)
    {
        L.head = L.tail = p;
        p->next = NULL;
    }
    else
    {
        L.tail->next = p;
        p->next = NULL;
        p = L.tail;
    }
}
void Insert(Hashtable& hashtable, Hocsinh hs)
{
    double hesotai = double(hashtable.n+1) / hashtable.M;
    if (hesotai > LOAD) return;
    int index = Hash(hashtable, hs.Maso);
    addtail(hashtable.table[index], hs);
    hashtable.n++;
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
int main()
{
    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}





