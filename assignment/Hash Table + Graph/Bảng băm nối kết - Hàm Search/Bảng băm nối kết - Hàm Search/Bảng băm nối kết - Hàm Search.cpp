
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
void Input(Hocsinh& x) {
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
/*MỘT SỐ LƯU Ý TRONG TEMPLATE NÀY
Trong các bài tập Search, Delete, input là bảng băm đã có.
Tức là trước đó, GV đã thêm các phần tử vào bảng băm (theo đúng kỹ thuật của bài Insert),
sau đó xuất toàn bộ bảng băm đó ra file inputx.txt (lần lượt xuất từng List ứng với mỗi địa chỉ).

Đoạn code bên dưới tái hiện lại bảng băm đã có nên SV không cần viết lại hàm Insert, chỉ cần tập trung vào chức năng Search
for (int i = 0; i < m; i++) { //duyệt từng List ứng với mỗi địa chỉ
        cin >> k; //số phần tử trong List[i]
        hashtable.n += k; //tăng số lượng phần tử trong bảng băm theo số lượng phần tử của List[i]
        for (int j = 0; j < k; j++) { //lần lượt nhập k học sinh và thêm vào cuối danh sách List[i]
            Input(hs);
            AddTail(hashtable.table[i], hs);
        }
}
*/

void InitList(List& L)
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
        InitList(hashtable.table[i]);
    }
}
void AddTail(List& L, Hocsinh hs)
{
    Node* p = new Node;
    p->data = hs;
    if (L.head==NULL)
    {
        L.head = L.tail = p;
        p->next = NULL;
    }
    else
    {
        L.tail->next = p;
        p->next = NULL;
        L.tail = p;
    }
}
Node* Search(Hashtable& hashtable, int k)
{
    int index = k  % hashtable.M;
    Node* curr = hashtable.table[index].head;
    while (curr)
    {
        if (curr->data.Maso == k) return curr;
        curr = curr->next;
    }
    return NULL;
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
        Node* p = Search(hashtable, k);

        if (p == NULL)
            cout << "KHONG TIM THAY\n";
        else {
            hs = p->data;
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        }
    }
    DeleteHashtable(hashtable);
    return 0;
}
