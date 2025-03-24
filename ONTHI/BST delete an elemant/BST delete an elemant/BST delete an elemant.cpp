#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node* left, * right;
};
typedef Node* Tree;
Node* getNode(int x)
{
	Node* p = new Node();
	p->val = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void insertTree(Tree& T,int x)
{
	if (T)
	{
		if (T->val == x) return;
		else if (T->val > x) insertTree(T->left, x);
		else if (T->val < x) insertTree(T->right, x);
	}
	else T = getNode(x);
}
void inputTree(Tree& T)
{
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		insertTree(T, x);
	}
}
void NLR(Tree T)
{
	if (!T) return;
	cout << T->val << " ";
	NLR(T->left);
	NLR(T->right);
}
Node* Search(Tree T, int x)
{
	if (!T) return NULL;
	if (T->val == x) return T;
	Node* left = Search(T->left, x);
	if (left) return left;
	return Search(T->right, x);
}
void replace(Node*& T, Node*& k)
{
	if (k->left)
	{
		replace(T, k->left);
	}
	else
	{
		T->val = k->val;
		Node* temp = k;
		k = k->right;
		delete temp;
	}
}
void deleteELe(Tree& T,int x)
{
	if (!T) return;
	if (T->val > x) deleteELe(T->left, x);
	else if (T->val < x) deleteELe(T->right, x);
	else
	{
		if (!T->left && !T->right)
		{
			Node* temp = T;
			T = NULL;
			delete temp;
		}
		else if (!T->left) {
			Node* temp = T;
			T = T->right;
			delete temp;
		}
		else if (!T->right)
		{
			Node* temp = T;
			T = T->left;
			delete temp;
		}
		else
		{
			replace(T, T->right);
		}
	}
}
int NodewithLevelK(Tree T, int k,int& dem)
{
	if (!T) return 0;
	if (k < 0) return 0;
	if (k == 0)
	{
		cout << T->val << " ";
		dem++;
	}

	NodewithLevelK(T->right, k - 1,dem);
	NodewithLevelK(T->left, k - 1,dem);
	return dem;
}
Node* rotateright(Tree& T)
{
	Node* p = T->left;
	T->left = p->right;
	p->right = T;
	return p;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	int dem = 0;
	int k;
	cin >> k;
	cout<<NodewithLevelK(T,k,dem);
	return 0;
}