
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
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = p;
    }
    else
    {
        L.pTail->next=p;
        L.pTail = p;
        p->next = NULL;
    }
}
void inputList(List& L, int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        addtail(L, x);
    }
}
void outputList(List L)
{
    node* p = L.pHead;
    if (L.pHead == NULL and L.pTail == NULL) cout << "List is empty";
    else
    {
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
    }
}
node* findMiddle(List L)
{
    node* p = L.pHead;
    int dem = 1;
    while (p != NULL)
    {
        dem++;
        p = p->next;
    }
    node* dau = L.pHead;
    node* cuoi = L.pHead;
    for (int j = 0; j < dem / 2; j++)
    {
        cuoi = cuoi->next;
    }
    while (cuoi != NULL)
    {
        cuoi = cuoi->next;
        dau = dau->next;
    }
    return dau;
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

    node* p = findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if (p)cout << "The middle element is " << p->info;

    return 0;
}
