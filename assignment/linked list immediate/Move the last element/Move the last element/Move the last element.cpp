
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
void moveLastToFront(List& L)
{
    if (L.pHead == nullptr || L.pHead->next == nullptr) {
        return;
    }
    node* p = L.pHead;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    L.pTail->next = L.pHead;
    L.pHead = L.pTail;
    p->next = NULL;
    L.pTail = p;
}
int main()
{
    List L;
    L.pHead = L.pTail = NULL;
    int n; cin >> n;
    inputList(L, n);
    cout << "Created List: " << endl;
    outputList(L);
    cout << endl;

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout << "Updated List after moving the last element to front of L: " << endl;
    outputList(L);
    return 0;
}
