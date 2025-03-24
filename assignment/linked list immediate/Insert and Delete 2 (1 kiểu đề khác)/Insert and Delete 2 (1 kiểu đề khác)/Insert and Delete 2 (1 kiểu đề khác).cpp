
#include <iostream>
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
void addtail(List& L,int& z)
{
	node* p = Getnode(z);
	if (p == NULL) return;
	if (!L.pHead)
		L.pHead = L.pTail = p;
	else
	{
		L.pTail->next = p;
		L.pTail = p;
		p->next = NULL;
	}
}
void addhead(List& L, int& z)
{
	node* p = Getnode(z);
	if (L.pHead == NULL)
		L.pHead = L.pTail = p;
	else
	{
		p->next = L.pHead;
		L.pHead = p;
	}
}
void deletehead(List& L)
{
	if (L.pHead == NULL) return;
	if (L.pHead == L.pTail) {
		delete L.pHead;   
		L.pHead = L.pTail = nullptr;  
	}
	else
	L.pHead = L.pHead->next;
}
void deletetail(List& L)
{
	if (L.pHead == NULL) return;
	if (L.pHead == L.pTail)
	{
		delete L.pHead;
		L.pHead = L.pTail = nullptr;
	}
	else
	{
		node* p = L.pHead;
		while (p->next!=L.pTail)
		{
			p = p->next;
		}
		delete L.pTail;
		L.pTail = p;
		L.pTail->next = NULL;
	}
}
	
void inputList(List& L, int& n)
{
	char x;  
	char y;  
	int z;   

	for (int i = 0; i < n; i++)
	{
		cin >> x; 
		switch (x)
		{
		case '+':
			cin >> y;  
			cin >> z;  
			if (y == 'T') {
				addtail(L, z);
			}
			else if (y=='H') addhead(L, z);
			break;  

		case '-':
			cin >> y;  
			cin >> z;  
			if (y == 'H') {
				deletehead(L);
			}
			else if (y=='T') deletetail(L);
			break;  
		}
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
int main()
{
	List L;
	Init(L);
	int n;
	cin >> n;
	inputList(L, n);
	outputList(L);
	return 0;
}