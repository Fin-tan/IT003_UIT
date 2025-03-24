
#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node* Tree;

Node* getNode(int x);
void insertNode(Tree& T, int x);
void inputTree(Tree& T);
void NLR(Tree T);
bool isSquare(int n);
void SearchStandFor(Node*& p, Node*& q); //Chon node phai nhat tren nhanh con ben trai
void deleteSquareNumbers(Tree& T);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "\nNLR: "; NLR(T);
    cout << "\nDelete all square numbers:";
    deleteSquareNumbers(T);
    cout << "\nNLR: "; NLR(T);

    return 0;
}
Node* getNode(int x)
{
    Node* p = new Node();
    p->info = x;
    p->pRight = NULL;
    p->pLeft = NULL;
    return p;
}
void insertNode(Tree& T, int x)
{
    if (T)
    {
        if (T->info == x) return;
        if (T->info > x) insertNode(T->pLeft, x);
        if (T->info < x) insertNode(T->pRight, x);
    }
    else T = getNode(x);
}
void inputTree(Tree& T)
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertNode(T, x);
    }
}
void NLR(Tree T)
{
    if (!T) return;
    cout << T->info << " ";
    NLR(T->pLeft);
    NLR(T->pRight);
}
bool isSquare(int n)
{
    if (n == 1) return true;
    for (int i = 1; i <= n / 2; i++)
    {
        if (i * i == n) return true;
    }
    return false;
}
void SearchStandFor(Node*& p, Node*& q)
{
    if (q->pRight != NULL)
    {
        SearchStandFor(p, q->pRight);
    }
    else
    {
        p->info = q->info;
        Node* temp = q;
        q = q->pRight;
        delete temp;
    }
}
void deleteSquareNumbers(Tree& T)
{
    if (T == NULL) return;
    deleteSquareNumbers(T->pLeft);
    deleteSquareNumbers(T->pRight);
    if (isSquare(T->info))
    {
        if (T->pLeft == NULL && T->pRight == NULL)
        {
            T = NULL;
            delete T;
        }
        else if (T->pLeft == NULL)
        {
            Node* p = T;
            T = T->pRight;
            delete p;
        }
        else if (T->pRight == NULL)
        {
            Node* p = T;
            T = T->pLeft;
            delete p;
        }
        else SearchStandFor(T, T->pLeft);
    }
}