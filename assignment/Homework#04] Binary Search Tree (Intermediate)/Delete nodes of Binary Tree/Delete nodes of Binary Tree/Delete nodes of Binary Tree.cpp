
#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node* left, * right;
};
typedef Node* Tree;
Node* getNode(int x)
{
    Node* p = new Node();
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
Node* Search(Tree T, int b)
{
    if (T == NULL) return NULL;
    if (T->info==b) return T;
    Node* left = Search(T->left, b);
    if (left) return left;
    return  Search(T->right, b);
}
void SetLeft(Node* node,int c)
{
    if (node == NULL) return;
    if (node->left == NULL)
        node->left = getNode(c);
}
void SetRight(Node* node, int c)
{
    if (node == NULL) return;
    if (node->right == NULL)
        node->right = getNode(c);
}
void LNR(Tree& T)
{
    if (T == NULL) return;
    LNR(T->left);
    cout << T->info << " ";
    LNR(T->right);
}
void DeleteLeft(Node* node)
{
    if (!node) {
        cout << "Node khong ton tai\n";
        return;
    }
    if (node->left == NULL) {
        cout << "Khong co node ben trai\n";
        return;
    }
    
    if (node->left->left != NULL || node->left->right != NULL)
    {
        cout << "Khong la node la nen khong xoa duoc\n";
        return;
    }
    if (node->left->left == NULL && node->left->right==NULL)
    {
        Node* Temp = node->left;
        node->left = NULL;
        delete Temp;
    }
}
void DeleteRight(Node* node)
{
    if (!node) {
        cout << "Node khong ton tai\n";
        return; 
    }
    if (node->right == NULL) cout << "Khong co node ben phai\n";
    else
        if (node->right->left != NULL || node->right->right) cout << "Khong la node la nen khong xoa duoc\n";
        else if (node->right->left == NULL && node->right->right == NULL)
        {
            Node* Temp = node->right;
            node->right = NULL;
            delete Temp;
        }
}
int main()
{
    Tree T = NULL;
    int x, b, c; char a;
    cin >> x;	T = getNode(x); // tao nut 32  goc
    while (true)
    {
        cin >> a; // Ky tu cho biet chen vao trai hay phai
        if (a != 'L' && a != 'R') break;
        cin >> b >> c;
        if (a == 'L') SetLeft(Search(T, b), c);
        else if (a == 'R') SetRight(Search(T, b), c);

    }
    cout << "LNR: "; LNR(T);
    cout << "\nDelete some nodes:\n";
    string s;
    while (true)
    {
        cin >> s; // Chuoi cho biet xoa ben trai hay ben phai
        if (s != "DL" && s != "DR") break;
        cin >> b;
        if (s == "DL") DeleteLeft(Search(T, b));
        else if (s == "DR") DeleteRight(Search(T, b));

    }
    cout << "\nLNR: "; LNR(T);

    return 0;
}
