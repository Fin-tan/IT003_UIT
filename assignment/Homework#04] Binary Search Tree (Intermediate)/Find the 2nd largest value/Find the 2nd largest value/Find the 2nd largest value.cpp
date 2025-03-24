
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
void secondLargest(Tree T)
{
	Node* current = T;
	Node* parent = NULL;
	if (!T || !current->left && !current->right)
	{
		return;
	}
	while (current->right != NULL)
	{
		parent = current;
		current = current->right;
	}
	if (current->left == NULL && current->right == NULL)
	{
		cout << "2nd largest value is " << parent->info;
	}
	else if (current->left != NULL)
	{
		Node* second = current->left;
		while (second->right != NULL)
		{
			second = second->right;
		}
		cout << "2nd largest value is " << second->info;
	}
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	secondLargest(T);
	return 0;
}