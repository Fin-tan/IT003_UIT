
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct node
{
    int info;
    node* left, * right;
};
typedef node* Tree;
node* getNode(int x)
{
    node* p = new node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}
void insertTree(Tree& T, int x)
{
    if (!T) T = getNode(x);
    else
    {
        if (T->info == x) return;
        if (x < T->info) insertTree(T->left, x);
        else insertTree(T->right, x);
    }

}
void inputTree(Tree& T)
{
    int n, x; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertTree(T, x);
    }
}
void LRN(Tree T)
{
    stack <node*> st1, st2;
    node* current = T;
    st1.push(T);
    while (!st1.empty())
    {
        current = st1.top();
        st1.pop();
        st2.push(current);
        if (current->left)
        {
            st1.push(current->left);
        }
        if (current->right)
        {
            st1.push(current->right);
        }
    }
    while (!st2.empty())
    {
        cout << st2.top()->info << " ";
        st2.pop();
    }
}
int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "\nLRN: "; LRN(T);
    return 0;
}
