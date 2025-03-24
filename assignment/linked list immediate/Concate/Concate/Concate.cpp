
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
    node* head, * tail;
};
void Init(List& L)
{
    L.head = NULL;
    L.tail = NULL;
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
    if (L.head == NULL && L.tail == NULL)
    {
        L.head = p;
        L.tail = p;
    }
    else
    {
        L.tail->next = p;
        L.tail = p;
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
    node* p = L.head;
    if (L.head == NULL)
        cout << "List is empty";
    else
    {
        while (p != NULL)
        {
            cout << p->info <<" ";
            p = p->next;
        }
    }
}
void concate(List& L1, List& L2)
{
    if (L1.head == NULL)
        L1.head = L2.head;
    else
    L1.tail->next = L2.head;
}
int main()
{
    List L1, L2;
    Init(L1); Init(L2);

    int n; cin >> n;
    inputList(L1, n);
    cout << "Created 1st List: " << endl;
    outputList(L1);
    cout << endl;

    cin >> n;
    inputList(L2, n);
    cout << "Created 2nd List: " << endl;
    outputList(L2);
    cout << endl;

    concate(L1, L2); // Noi L2 vao L1
    cout << "Updated L1: " << endl;
    outputList(L1);

    return 0;
}
