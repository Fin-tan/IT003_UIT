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
		if (T->val > x)
			insertTree(T->left, x);
		if (T->val < x)
			insertTree(T->right, x);
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
void NLR(Tree T)
{
	if (!T) return;
	cout << T->val << " ";
	NLR(T->left);
	NLR(T->right);
}
void LRN(Tree T)
{
	if (!T) return;
	LRN(T->left);
	LRN(T->right);
	cout << T->val << " ";
}
void LNR(Tree T)
{
	if (!T) return;
	LNR(T->left);
	cout << T->val << " ";
	LNR(T->right);
}
Node*  SearchBST(Tree& T, int x)
{
	if (!T)
	{
		return NULL;
	}
	if (T->val == x)
	{
		return T;
	}
	Node* left=SearchBST(T->left,x);
	if (left) return left;
	return SearchBST(T->right, x);
}
int MaxBST(Tree T)
{
	
	while (T->right)
	{
		T = T->right;
	}
	return T->val;
}
int MinBST(Tree T)
{
	while (T->left)
	{
		T = T->left;
	}
	return T->val;
}
void LeafNode(Tree T)
{
	if (T == NULL) return;
	LeafNode(T->left);
	if (T->right==NULL and !T->left) cout << T->val<<" ";
	LeafNode(T->right);
}
void Node1con(Tree T)
{
	if (!T) return;
	Node1con(T->left);
	if ((T->right and !T->left) or (!T->right and T->left))
	cout << T->val << " ";
	Node1con(T->right);
}
void Node2con(Tree T)
{
	if (!T) return;
	if (T->right and T->left)
		cout << T->val << " ";
	Node2con(T->left);
	Node2con(T->right);
}
void nodetrong(Tree T, int check)
{
	if (!T) return;
	if ((T->left || T->right) && check != 0) cout << T->val << " ";
	nodetrong(T->left,1);
	nodetrong(T->right, 1);
}
int treeHeight(Tree T)
{
	if (T == NULL) return 0; // Cây r?ng có chi?u cao là 0
	int leftHeight = treeHeight(T->left);  // Chi?u cao c?a cây con bên trái
	int rightHeight = treeHeight(T->right); // Chi?u cao c?a cây con bên ph?i
	return 1+ max(leftHeight, rightHeight); // Chi?u cao c?a cây hi?n t?i
}
Node* rotateleft(Tree& T)
{
	if (!T || T->right == NULL) {
		cout << "Khong the xoay\n"; return T;
	}
	Node* b = T->right;
	Node* c = b->left;
	b->left = T;
	T->right = c;
	return b;
}
void replaceNode(Node*& p, Node*& K)
{
	if (K->right)
	{
		replaceNode(p,K->right);
	}
	else
	{
		p->val = K->val;
		Node* temp = K;
		K = K->left;
		delete temp;
	}
}
void deleteRoot1(Tree& T)
{
	if (T == NULL) return;
	Node* p = T;
	if (T->left == NULL)
	{
		T = T->right;
	}
	else if (T->right == NULL)
	{
		T = T->left; 
	}
	else
	{
		replaceNode(p, T->right);
		return;
	}
	delete p;
}
void deleteroot(Tree& T,int m)
{
	for (int i = 0; i < m; i++)
	{
		if (T == NULL) return;
		deleteRoot1(T);
	}
}
void deleteELe(Tree& T, int x)
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
			replaceNode(T, T->left);
		}
	}
}
int NodewithLevelK(Tree T, int k, int& dem)
{
	if (!T) return 0;
	if (k < 0) return 0;
	if (k == 0)
	{
		cout << T->val << " ";
		dem++;
	}

	NodewithLevelK(T->right, k - 1, dem);
	NodewithLevelK(T->left, k - 1, dem);
	return dem;
}
Node* rotateright(Tree& T)
{
	Node* p = T->left;
	T->left = p->right;
	p->right = T;
	return p;
}
void deleleafall(Tree& T)
{
	if (!T) return;
	if (!T->left && !T->right)
	{
		Node* temp = T;
		T = NULL;
		delete temp;
	}
	else
	{
		deleleafall(T->left);
		deleleafall(T->right);
	}
}
bool isSquare(int n)
{
	if (n == 1) return true;
	for (int i = 1; i <= n / 2; i++)
	{
		if (i * i == n) return true;
	}
	return false;
}
void Deleteallsquarenumbers(Tree& T)
{
	if (!T) return;

	Deleteallsquarenumbers(T->left);
	Deleteallsquarenumbers(T->right);
	if (isSquare(T->val))
	{
		deleteELe(T,T->val);
		return;
	}

}
int isfullbst(Tree& T)
{
	if (!T) return 1;
	if ((!T->left && T->right) || (T->left && !T->right))
	{
		return 0;
	}
	int left = isfullbst(T->left);
	int right = isfullbst(T->right);
	return left & right;
}
void findapath(Tree T, int x)
{
	Node* p = SearchBST(T, x);
	if (p)
	{
		while (T->val != x)
		{
			cout << T->val << " ";
			if (T->val > x) T = T->left; else T = T->right;
		}
		cout << T->val;
	}

}
void  Findthe2ndlargestvalue(Tree T)
{
	Node* parent = NULL;
	if (!T || !T->left && !T->right) return;
	while (T->right)
	{
		parent = T;
		T = T->right;
	}
	if (!T->left)
	{
		cout << parent->val;
	}
	else
	{
		Node* second = T->left;
		while (second->right)
		{
			second = second->right;
		}
		cout << second->val;
	}
}
void Findfloorofx(Tree T,int x)
{
	int floot = 0;
	while (T)
	{
		if (T->val == x)
		{
			floot = T->val;
			break;
		}
		if (T->val < x)
		{
			floot = T->val;
			T = T->right;
		}
		else
		{
			floot = T->val;
			T = T->left;
		}
	}
	cout << floot;
}
int main()
{
	Tree T=NULL;
	int m;
	inputTree(T);
	int x;
	cin >> x;
	Findfloorofx(T,x);
	return 0;
}