
#include <iostream>
using namespace std;
struct Node {
	int info;
	Node* left;
	Node* right;
};

Node* getNode(int x) {
	Node* p = new Node();
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

typedef Node* Tree;

void insertTree(Tree& T, int x) {
	if (T) {
		if (T->info == x) return;
		if (T->info > x) insertTree(T->left, x);
		if (T->info < x) insertTree(T->right, x);
	}
	else {
		T = getNode(x);
	}
}

void inputTree(Tree& T) {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insertTree(T, x);
	}
}

void floor(Tree T,int x)
{
	int floor = 201;
	while (T)
	{
		if (T->info == x) {
			floor = T->info;
			break;
		}
		else if (T->info < x)
		{
			floor = T->info;
			T = T->right;
		}
		else T = T->left;
	}
	cout << floor;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	int x;
	cin >> x;
	floor(T,x);
	return 0;
}
