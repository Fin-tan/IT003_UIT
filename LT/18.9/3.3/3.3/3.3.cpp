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
node* getNode(int x)
{
	node* p = new node;
	p->infor = x;
	p->next = NULL;
	return p;
}
void addHead(List& L, int &y)
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
void printList(List& L)
{
	node* p = L.head;
	while (p != NULL)
	{
		cout << p->infor << " ";
		p = p->next;
	}
}
node* searchls(List& L,int x)
{
	node* p = L.head;
	while (p != NULL)
	{
		if (p->infor == x) return p;
		p = p->next;
	}
	return NULL;
}
void addafter(List& L, int x, int y)
{
	node* k = searchls(L,x);
	if (k == NULL) addHead(L, y);
	else
	{
		node* p = getNode(y);
		p->next = k->next;
		k->next = p;
	}
}
int main()
{
	List l;
	int x,a, y;
	l.head = l.tail = NULL;
	while (1)
	{
		cin >> x;
		if (x == 3) break;
		if (x == 0)
		{
			cin >> y;
			addHead(l, y);
		}
		if (x == 1)
		{
			cin >> y;
			addTail(l, y);
		}
		if (x == 2)
		{
			cin >> a;
			cin >> y;
			addafter(l, a, y);
		}
	}
	printList(l);
	return 0;
}