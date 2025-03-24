
#include <iostream>
using namespace std;



struct Node
{
	int info;
	Node* pNext;
};
struct List
{
	Node* pHead, * pTail;
};

Node* getNode(int y)
{
	Node* p=new Node();
	p->info = y;
	p->pNext = NULL;
	return p;
}
void addHead(List& L, int y)
{
	Node* p = getNode(y);
	if (L.pHead == NULL && L.pTail == NULL)
	{
		L.pHead = L.pTail = p;
		p->info = y;
	}
	else
	{
		p->pNext = L.pHead;
		p->info = y;
		L.pHead = p;
	}
}
void addTail(List& L, int y)
{
	Node* p = getNode(y);
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = p;
		p->info = y;
	}
	else
	{
		L.pTail->pNext = p;
		p->pNext = NULL;
		p->info = y;
		L.pTail = p;
	}
}
Node* searchEle(List L, int x)
{
	Node* p = L.pHead;
	while (p != NULL)
	{
		if (p->info == x) return p;
		p = p->pNext;
	}
	return NULL;
}
void addAfter(List& L, int x, int y)
{
	Node* k = searchEle(L, x);
	Node* p = getNode(y);
	if (k == NULL) addHead(L, y);
	else
	{
		if (k == L.pTail) addTail(L, y);
		else
		{
			p->pNext = k->pNext;
			k->pNext = p;
		}
	}
}
void deleteHead(List& L)
{
	if (L.pHead == NULL) return;
	if (L.pHead == L.pTail)
	{
		L.pHead = L.pTail = NULL;
	}
	else
		L.pHead = L.pHead->pNext;
}
void deletail(List& L)
{
	if (L.pHead == NULL) return;
	if (L.pHead == L.pTail)
	{
		L.pHead = L.pTail = NULL;
	}
	else
	{
		Node* p = L.pHead;
		while (p->pNext != L.pTail)
		{
			p = p->pNext;
		}
		delete L.pTail;
		L.pTail = p;
		L.pTail->pNext = NULL;
	}
}
void deleteNode(List& L, int x)
{
	Node* p = L.pHead;
	Node* k = searchEle(L, x);
	if (k == NULL) return;
	else
	{
		if (k == L.pHead) deleteHead(L);
		else
			if (k == L.pTail) deletail(L);
			else
			{
				while (p->pNext != k)
					p = p->pNext;
				p->pNext = k->pNext;
				delete k;

			}
	}
}
void deleteAll(List& l, int x) {
	Node* p = l.pHead;
	Node* prev = NULL;
	while (p != NULL) {
		if (p->info == x) {
			if (prev == NULL) {
				l.pHead = p->pNext;
				if (l.pTail == p)
					l.pTail = NULL;
			}
			else {
				prev->pNext = p->pNext;
				if (l.pTail == p)
					l.pTail = prev;
			}
			Node* temp = p;
			p = p->pNext;
			delete temp;
		}
		else {
			prev = p;
			p = p->pNext;
		}
	}
}


void printlist(List L)
{
	Node* p = L.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;

	}
}
int main()
{
	List L;
	L.pHead = NULL;
	L.pTail = NULL;
	int x, y;
	while (1)
	{
		cin >> x;
		if (x == 6) break;
		if (x == 0)
		{
			cin >> y;
			addHead(L, y);
		}
		if (x == 1)
		{
			cin >> y;
			addTail(L, y);
		}
		if (x == 2)
		{
			int a;
			cin >> a;
			cin >> y;
			addAfter(L, a, y);
		}
		if (x == 5)
		{
			deleteHead(L);
		}
		if (x == 3)
		{
			cin >> x;
			deleteNode(L, x);
		}
		if (x == 4)
		{
			cin >> x;
			deleteAll(L, x);
		}
	}
	if (L.pHead == NULL && L.pTail == NULL) cout << "blank"; else printlist(L);
}