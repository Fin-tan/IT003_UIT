#include <iostream>
using namespace std;
struct node
{
	int infor;
	node* next;
};
struct List
{
	node* head, * tail;
};
node* getNode(int y)
{
	node* p;
	p = new node;
	p->infor = y;
	p->next = NULL;
	return p;
}
void addHead(List& L, int& y)
{
	node* p = getNode(y);
	if (L.head == NULL && L.tail == NULL)
	{
		L.head = L.tail = p;
	}
	else
	{
		p->next = L.head;
		L.head = p;
	}
}
void addTail(List& L, int& y)
{
	node* p = getNode(y);
	if (L.head == NULL && L.tail == NULL)
	{
		L.head = L.tail = p;
	}
	else
	{
		p->next = NULL;
		L.tail->next = p;
		L.tail = p;
	}
}
node* searchELE(List L, int x)
{
	node* p = L.head;
	while (p != NULL)
	{
		if (p->infor == x) return p;
		p = p->next;
	}
	return NULL;
}
void Addafter(List& L, int x,int y)
{
	node* k = searchELE(L, x);
	if (k == NULL) addHead(L, y);
	else
	{
		node* p = getNode(y);
		p->next = k->next;
		k->next = p;
	}
}
void printlist(List& L)
{
	node* p = L.head;
	while (p != NULL)
	{
		cout << p->infor << " ";
		p = p->next;
	}
}
int main()
{
	List L;
	int x, y;
	L.head = L.tail = NULL;
	while (1)
	{
		cin >> x;
		if (x == 3) break;
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
			cin >> x >> y;
			Addafter(L, x, y);
		}
	}
	printlist(L);
}