
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
int countNodes(Tree T)
{
	if (T == NULL) return 0;
	return 1 + countNodes(T->left) + countNodes(T->right);
}
int depthOfTree(Tree T)
{
	if (T == NULL) return -1;
	return max(depthOfTree(T->left), depthOfTree(T->right)) + 1;
}
void countEven(Tree T,int & count_even)
{
	if (T != NULL)
	{
		countEven(T->left, count_even);
		if (T->info % 2 == 0) count_even++;
		countEven(T->right, count_even);
	}
}
void countOdd(Tree T, int& count_odd)
{
	if (T != NULL)
	{
		countOdd(T->left, count_odd);
		if (T->info % 2 != 0) count_odd++;
		countOdd(T->right, count_odd);
	}
}
int countNegative(Tree T) {
	if (T == NULL) {
		return 0; 
	}

	
	return countNegative(T->left) + (T->info < 0 ? 1 : 0) + countNegative(T->right);
}
int	countPositive(Tree T) {
	if (T == NULL) {
		return 0;
	}


	return countPositive(T->left) + (T->info > 0 ? 1 : 0) + countPositive(T->right);
}
bool isPrime(int n) {
	if (n <= 1) return false; 
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false; 
	}
	return true; 
}

int countPrime(Tree T)
{
	if (T == NULL) return 0;
	return countPrime(T->left) + (isPrime(T->info) ? 1 : 0) + countPrime(T->right);
}
void listPrime(Tree T)
{
	if (T == NULL) {
		return; // 
	}

	
	

	
	if (isPrime(T->info)) {
		cout << T->info << " "; 
	}
	listPrime(T->left);
	listPrime(T->right);
	
}
int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "LNR: "; LNR(T); cout << endl;

    cout << "Number of nodes: " << countNodes(T) << endl;
    cout << "Depth of Tree: " << depthOfTree(T) << endl;

    int count_even = 0, count_odd = 0;
    countEven(T, count_even); countOdd(T, count_odd);
    cout << "Number of even nodes: " << count_even << endl;
    cout << "Number of odd nodes: " << count_odd << endl;

	 cout << "Number of positive nodes: " << countPositive(T) << endl;
	  cout << "Number of negative nodes: " << countNegative(T) << endl;

    cout << "Number of prime nodes: " << countPrime(T) << endl;
    cout << "Prime numbers: "; listPrime(T);



    return 0;
}
