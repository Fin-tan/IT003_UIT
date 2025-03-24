#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct node
{
	int info;
	node* next;
};
struct List
{
	node *pHead, *pTail;
};
node* Getnode(int x)
{
	node* p = new node();
	p->info = x;
	p->next = NULL;
	return p;
}
void Init(List& L)
{
	L.pHead = L.pTail = NULL;
}
void addtail(List &L, int &x)
{
		node* p = Getnode(x);
		if (p == NULL) return;
		if (L.pHead == NULL) 
		{ 
			L.pHead = p;
			L.pTail = p;
		}
		L.pTail->next = p;
		L.pTail = p;
		p->next = NULL;
}
void inputList(List &L, int& n)
{
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		addtail(L, x);
	}
}
void outputList(List L)
{
	node* p = L.pHead;
	if (L.pHead ==NULL && L.pTail == NULL) cout << "List is empty";
	else
	{
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->next;
		}
	}
}
node* findMax(List L)
{
	node* p = L.pHead;
	if (L.pHead == NULL) cout << "List is empty";
	node* max = p;
	while (p != NULL)
	{
		if (p->info > max->info) max = p;
		p = p->next;
	}
	return max;
}
int main()
{
	List L;
	Init(L);
	int n; cout << "Enter a number: "; cin >> n;
	cout << "\nEnter a sequence of " << n << " numbers: ";
	inputList(L, n);
	cout << "\nThe created Linked List: ";
	outputList(L);
	cout << "\nThe maximum value: ";
	node* p = findMax(L);
	if (p) cout << p->info;

	return 0;
}
