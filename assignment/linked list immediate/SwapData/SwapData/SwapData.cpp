
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct node
{
    int info;
    node* next;
};
struct List
{
    node* pHead, * pTail;
};
void Init(List& L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
node* getnode(int x)
{
    node* p = new node();
    p->info = x;
    p->next = NULL;
    return p;
}
void addtail(List& L, int x)
{
    node* p = getnode(x);
    if (L.pHead == NULL && L.pTail == NULL)
    {
        L.pHead = p;
        L.pTail = p;
    }
    else
    {
        L.pTail->next = p;
        L.pTail = p;
        p->next = NULL;
    }
}
void inputList(List& L, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        addtail(L, x);
    }
}
void outputList(List L)
{
    node* p = L.pHead;
    if (L.pTail == NULL)
        cout << "List is empty";
    else
    {
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
    }
}
node* swapData(List& L, int x, int y)
{
    node* p = L.pHead;
    node* q = L.pHead;
    while (p != NULL && p->info != x)
    {
        p = p->next;
    }
    while (q != NULL && q->info != y)
    {
        q = q->next;
    }
    if (p != nullptr && q != nullptr) {
        swap(p->info, q->info);
        return p;
    }
    else return NULL;
}
int main()
{
    List L;
    L.pHead = L.pTail = NULL;
    int n; cin >> n;
    inputList(L, n);
    cout << "Created List: " << endl;
    outputList(L); // Neu ds rong thi xuat "List is empty"
    cout << endl;

    int x, y; cin >> x >> y;
    node* p = swapData(L, x, y);
    /* Tim 2 node chua x va y,
    Hoan vi gia tri cua 2 node do,
    nghia la: Lien ket giua cac node khong thay doi, node ban dau chua x se doi lai la chua y
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout << "Updated List after swapping " << x << " and " << y << ": " << endl;
    outputList(L);
    cout << endl;

    /* Kiem tra xem co that su hoan vi info cua 2 node khong
    Neu hoan vi info thi node chua x ban dau se doi lai chua y*/

    if (p) // co hoan vi
    {
        cout << "At the address of " << x << ": ";
        cout << p->info;
    }
    else cout << "Can not swap";
    return 0;
}
