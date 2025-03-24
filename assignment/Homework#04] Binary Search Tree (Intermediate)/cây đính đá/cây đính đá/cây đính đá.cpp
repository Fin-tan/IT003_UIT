#include <iostream>
using namespace std;
struct Nodee
{
    int info;
    Nodee* next;
};
struct List
{
    Nodee* head,*tail;
};
struct Node
{
    string key;
    List L;
    Node* Left, * Right;
};
Nodee* getNodeList(int x)
{
    Nodee* p = new Nodee();
    p->info = x;
    p->next = NULL;
    return p;
}
void addTail(List& L, int y) {
    Nodee* p = getNodeList(y);
    if (L.head == NULL) {
        L.head = L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}
Node* getNodeBST(string key,int weight)
{
    Node* p = new Node();
    p->key = key;
    p->L.head = p->L.tail = NULL;
    addTail(p->L, weight);
    p->Left = NULL;
    p->Right = NULL;
    return p;
}

typedef Node* Tree;

void insertTree(Tree& T, string key, int weight)
{
    if (T)
    {
        if (T->key == key) addTail(T->L, weight);
        if (T->key > key) insertTree(T->Left, key, weight);
        if (T->key < key) insertTree(T->Right, key, weight);
    }
    else T = getNodeBST(key, weight);
}

void inputTree(Tree& T)
{
    string key;
    int weight;
    while (true)
    {
        cin >> key;
        if (key == "-1")
            break;
        cin >> weight;
        insertTree(T, key, weight);
    }
}
int findweight(List L,int weight)
{
    int dem=0;
    Nodee* p = L.head;
    while (p)
    {
        if (p->info == weight)
        {
            break;
        }
        else dem++;
        p = p->next;
    }
    return dem;
}
void findstone(Tree T,string key,int weight)
{
    int dem = 1;
    while (T)
    {
        if (T->key == key)
        {
            cout << dem<< " ";
            cout << findweight(T->L, weight);
            break;
        }
        if (T->key > key)
        {
            dem++;
            T = T->Left;
        }
        else if (T->key < key)
        {
            dem++;
            T = T->Right;
        }
    }
}


int main()
{
    Tree T = NULL;
    inputTree(T);

    string key;
    int m;
    cin >> key >> m;    
    findstone(T, key, m);

    return 0;
}
