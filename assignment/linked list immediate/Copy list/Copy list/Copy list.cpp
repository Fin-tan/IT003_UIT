
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int val;
    Node* next;
};

struct List {
    Node* head, * tail;
};

void list_initializing(List& l) {
    l.head = l.tail = NULL;
}

Node* getNode(int x)
{
    Node* p = new Node();
    p->val = x;
    p->next = NULL;
    return p;
}
void add_tail(List& L, int x)
{
    Node* p = getNode(x);
    if (L.head == NULL and L.tail == NULL)
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
void copy(List &L, List &L1)
{
    Node* p = L.head;
    while (p != NULL)
    {
        add_tail(L1, p->val);
        p = p->next;
    }
}
int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l; list_initializing(l);
    //Read list
    int x;
    do {
        cin >> x;
        add_tail(l, x);
    } while (x != 0);

    List l2; list_initializing(l2);
    copy(l, l2);

    Node* p = l.head, * q = l2.head;
    while (p != NULL) {
        if (p == q || p->val != q->val) cout << "WRONG";
        cout << p->val << endl;
        p = p->next;
        q = q->next;
    }

    return 0;
}
