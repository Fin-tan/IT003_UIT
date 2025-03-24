
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
void replaceNode(node*& T, node*& rightSubtree)
{
	if (rightSubtree->left != NULL)
	{
		replaceNode(T, rightSubtree->left);
	}
	else
	{
		T->info = rightSubtree->info;
		node* temp = rightSubtree;
		rightSubtree = rightSubtree->right;
		delete temp;
		
	}
}

void deleteNode(Tree& T, int x)
{
	if (T == NULL) return;
	if (T->info > x) return deleteNode(T->left, x);
	if (T->info < x) return deleteNode(T->right, x);
	else
	{
		if (T->left == NULL && T->right == NULL)
		{
			T = NULL;
			delete T;
			
		}
		else if (T->left == NULL)
		{
			node* p = T;
			T = T->right;
			delete p;
		}
		else if (T->right == NULL)
		{
			node* p = T;
			T = T->left;
			delete p;
		}
		else replaceNode(T, T->right);
	}
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "NLR: "; NLR(T);
	int x; cout << "\nEnter the element you want to delete: "; cin >> x;
	deleteNode(T, x);
	cout << "\nNLR: "; NLR(T);

	return 0;
}
