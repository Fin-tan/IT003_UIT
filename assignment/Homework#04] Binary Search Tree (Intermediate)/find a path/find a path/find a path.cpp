#include <iostream>
#include <vector>
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
void insertNode(Tree& T, int x)
{
	if (T)
	{
		if (T->info == x) return;
		if (T->info > x) insertNode(T->left, x);
		if (T->info < x) insertNode(T->right, x);
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
		insertNode(T, x);
	}
}
Node* search(Node* root, int key) {

	if (root == NULL || root->info == key)
		return root;
	if (root->info < key)
		return search(root->right, key);

	return search(root->left, key);
}
void findPath(Tree T, int x)
{
	static bool check = false;
	static vector<int> path;

	if (!search(T, x))
	{
		cout << "Not found";
		return;
	}

	else {
		if (!T) return;
		if (T->info > x) {
			path.push_back(T->info);
			findPath(T->left, x);
		}
		if (T->info < x)
		{
			path.push_back(T->info);
			findPath(T->right, x);
		}
		if (T->info == x)
		{
			check = true;
			path.push_back(T->info);
			if (check == true) cout << "Found. Path: ";
			for (auto& i : path)
				cout << i << " ";
			return;
		}
	}

}

int main()
{
	
	Tree T=NULL;
	int x;
	inputTree(T);
	cin >> x;
	findPath(T, x);
	return 0;
}