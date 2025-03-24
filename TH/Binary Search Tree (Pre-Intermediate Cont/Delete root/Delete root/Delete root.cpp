
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
void replaceNode(node*& p, node*& k)
{
	if (k->left != NULL)
	{
		replaceNode(p, k->left);
	}
	else
	{
		p->info = k->info;
		node* temp = k;
		k = k->right;
		delete temp;
	}
}

void deleteRoot1(Tree& T)
{
	if (T == NULL) return ;
	node* p=T;
	if (T->right == NULL)
	{
		
			T = T->left;
		
	}
	else if (T->left == NULL)
		T = T->right;
	else
	{
		replaceNode(p, T->right);
		return;
	}
	delete p;
}
void deleteRoot(Tree& T, int m)
{
	for (int i = 0; i < m; i++)
	{
		if (T == NULL) return;
		deleteRoot1(T);
	}
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "NLR: "; NLR(T);
	int m; cout << "\nEnter m: "; cin >> m;
	deleteRoot(T, m);
	cout << "\nNLR: "; NLR(T);

	return 0;
}
