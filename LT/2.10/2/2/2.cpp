
#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node* left, * right;
};
typedef Node* Tree;
Node* getnode(int x)
{
	Node* p = new Node();
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
Node* Search(Tree T, int x)
{
	Node* p = getnode(x);
	if (p->info == T->info) return p;
	if (p->info < T->info) return Search(T->left, x);
	if (p->info > T->info) return Search(T->right, x);
}
int minValue(Tree T)
{
	while (T->left != NULL)
	{
		T = T->left;
	}
	return T->info;
}
; int maxValue(Tree T)
{
	while (T->right != NULL)
	{
		T = T->right;
	}
	return T->info;
}
int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "LNR: "; LNR(T); cout << endl;


    int x; cout << "\nEnter the element you want to find: "; cin >> x;
    Node* p = Search(T, x);
    if (p) cout << "Found";
    else cout << "Not found";
    cout << "\nMinimum value in BTS is " << minValue(T);
    cout << "\nMinimax value in BTS is " << maxValue(T);


    return 0;
}
