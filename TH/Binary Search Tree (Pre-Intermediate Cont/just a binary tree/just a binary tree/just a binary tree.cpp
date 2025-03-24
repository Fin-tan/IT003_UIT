
#include <iostream>
using namespace std;

struct node
{
	int info;
	node* left, * right;
};
typedef node* Tree;
node* getNode(int x)
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
	else T = getNode(x);
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
node* Search(Tree T, int x)
{
    if (T == NULL) return NULL;
    if (T->info == x) return T; 
    node* p = Search(T->left, x);
    if (p != NULL) return p;
    return Search(T->right, x);
}

void SetLeft(node* p, int c)
{
    if (p == NULL)
    {
        cout << "Node khong ton tai\n";
        return;
    }
    if (p->left != NULL)
    {
        cout << "Da co node con ben trai\n";
        return;
    }
    p->left = getNode(c);
}

void SetRight(node* p, int c)
{
    if (p == NULL)
    {
        cout << "Node khong ton tai\n";
        return;
    }
    if (p->right != NULL)
    {
        cout << "Da co node con ben phai\n";
        return;
    }
    p->right = getNode(c);
}

int main()
{
    Tree T = NULL;
    int x, b, c; char a;
    cin >> x;	T = getNode(x); 
    while (true)
    {
        cin >> a; 
        if (a != 'L' && a != 'R') break; 
        cin >> b >> c;
        if (a == 'L') SetLeft(Search(T, b), c); 
        else if (a == 'R') SetRight(Search(T, b), c); 
    }
    cout << "\nLNR: "; LNR(T); cout << endl;

    return 0;
}
