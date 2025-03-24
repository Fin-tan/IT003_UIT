#include <iostream>
using namespace std;

struct node
{
    int info;
    node* left, * right;
};

typedef node* Tree;

node* getnode(int x)
{
    node* p = new node();
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertTree(Tree& T, int x)
{
    if (T)
    {
        if (T->info == x) return;
        if (T->info > x)
            insertTree(T->left, x);
        if (T->info < x)
            insertTree(T->right, x);
    }
    else T = getnode(x);
}

void NLR(Tree T)
{
    if (!T) return;
    cout << T->info << " ";
    NLR(T->left);
    NLR(T->right);
}

void LRN(Tree T)
{
    if (T != NULL)
    {
        LRN(T->left);
        LRN(T->right);
        cout << T->info << " ";
    }
}

void LNR(Tree T)
{
    if (T != NULL)
    {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

void inputTree(Tree& T)
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertTree(T, x);
    }
}

node* turnLeft(node* a) {
    if (a == NULL || a->right == NULL) {
        cout << "Khong the xoay trai vi khong co nut con ben phai\n";
        return a; 
    }

    node* b = a->right; 
    node* c = b->left;  
    b->left = a;        
    a->right = c;      

    return b;         
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "NLR: ";
    LNR (T);
    return 0;
}
