#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* left,*right;
};
typedef Node* Tree;
Node* getnode(int x)
{
	Node* p = new Node();
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void insertTree(Tree& T, int x,int &dem)
{
	
	if (T != NULL)
	{
		if (T->data == x) {
			cout << "Bi trung gia tri, ket thuc qua trinh tao cay" << endl;
			dem++;
			return;
		}
		if (T->data > x) insertTree(T->left, x,dem);
		if (T->data < x) insertTree(T->right, x,dem);
	}
	else T = getnode(x);
}
void inputTree(Tree& T)
{
	int n,x;
	cin >> n;
	int dem=0;
	for (int i = 0; i < n; i++)
	{
		if (dem > 0) break;
		cin >> x;
		insertTree(T, x,dem);
	}

}
void NLR(Tree& T)
{
	if (!T) return;
	cout << T->data << " ";
	NLR(T->left);
	NLR(T->right);
}
int main()
{
	Tree T = NULL;
	inputTree(T); //Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
	cout << "NLR: "; NLR(T);
	return 0;
}



