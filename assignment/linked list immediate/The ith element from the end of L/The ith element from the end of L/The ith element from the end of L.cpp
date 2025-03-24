
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
	node* pHead, * pTail;
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
void addtail(List& L, int& x)
{
	node* p = Getnode(x);
	if (p == NULL) return;
	if (L.pHead == NULL)
	{
		L.pHead = p;
		L.pTail = p;
	}
	else {

		p->next = NULL;
		L.pTail->next = p;
		L.pTail = p;
	}
}
void inputList(List& L, int& n)
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
	if (L.pHead == NULL && L.pTail == NULL) cout << "List is empty";
	else
	{
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->next;
		}
	}
}
node* findElementFromEnd(List L, int i) 
{
	if (L.pHead == nullptr) 
	{
		std::cout << "List is empty";
		return nullptr;
	}
	node* cuoi = L.pHead;
	node* dau = L.pHead;
	for (int j = 0; j < i; j++)
	{
		if (cuoi == NULL)
		{
			cout << "The index is invalid";
			return NULL;
		}
		cuoi = cuoi->next;
	}
	while (cuoi != NULL)
	{
		cuoi = cuoi->next;
		dau = dau->next;
	}
	return dau;
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

    int i; cout << "\nEnter a number: "; cin >> i;
    cout << "\nThe element at index " << i << " (from the end of L): ";
	node* p = findElementFromEnd(L, i);
    if (p) cout << p->info;


    return 0;
}
