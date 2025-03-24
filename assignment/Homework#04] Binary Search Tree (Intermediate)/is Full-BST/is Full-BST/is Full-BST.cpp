
#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node* left, * right;
};

Node* getNode(int x)
{
	Node* p = new Node();
	
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	
	return p;
}
typedef Node* Tree;
void insertTree(Tree& T, int x)
{

	if (T)
	{
		if (T->info == x) return;
		if (T->info > x) insertTree(T->left, x);
		if (T->info < x) insertTree(T->right, x);
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
		insertTree(T, x);
	}
}
void LNR(Tree T)
{
	if (!T) return;
	LNR(T->left);
	cout << T->info << " ";
	LNR(T->right);
}
int  isFullBinaryTree(Tree T)
{
	if (T==NULL) return 1;
	if ((T->left == NULL && T->right != NULL)
		|| (T->left != NULL && T->right == NULL))
		return 0;
	
		int left = isFullBinaryTree(T->left);
		int right = isFullBinaryTree(T->right);
	
	
	return left && right;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "LNR: "; LNR(T);
	int i = isFullBinaryTree(T);
	if (i == 0) cout << "\nThe tree is not a Full Binary Tree";
	else cout << "\nThe tree is a Full Binary Tree";
	return 0;
}

