#include<iostream>
using namespace std;
struct Node
{
	int val;
	Node* next;
};
struct List
{
	Node* head,* tail;
};
Node* getNode(int x)
{
	Node* p = new Node();
	p->val = x;
	p->next = NULL;
	return p;
}
void InitList(List& L)
{
	L.head = L.tail = NULL;
}
void addhead(List& L, int x)
{
	Node* p = getNode(x);
	if (L.head == NULL)
	{
		L.head =L.tail= p;
	}
	else
	{
		p->next = L.head;
		L.head = p;
	}
}
void addtail(List& L,int x)
{
	Node* p = getNode(x);
	if (!L.head)
	{
		L.head = L.tail = p;
	}
	else
	{
		L.tail->next = p;
		L.tail = p;
	}
}
Node* searchNode(List& L, int x)
{
	Node* p = L.head;
	while (p)
	{
		if (p->val == x) { return p; }
		p = p->next;
	}
	return NULL;
}
void addafter(List& L, int x,int y)
{
	Node* next = getNode(y);
	Node* p = searchNode(L, x);
	if (p == NULL) addhead(L, y);
	else if (p == L.tail) addtail(L, y);
	else
	{
		
		next->next = p->next;
		p->next = next;
	}
}
void deletehead(List& L)
{
	if (L.head == NULL) return;
	else if (L.head == L.tail) L.head = L.tail = NULL;
	else
	{
		L.head = L.head->next;
	}
}
void deleteEle(List& L,int x)
{
	Node* q = L.head;
	Node* p = searchNode(L,x);
	if (p == NULL) return;
	if (p == L.head) deletehead(L);
	else
	{
		while (q->next!=p)
		{
			q = q->next;
		}
		q->next = p->next;
		if (p == L.tail);
		L.tail = q;
	}
	delete p;
}
void inputList(List& L)
{
	int n,x,y;
	while (true)
	{	
		cin >> n;
		switch (n)
		{
		case 0:
		{
			cin >> x;
			addhead(L, x);
			break;
		}
		case 1:
		{
			cin >> x;
			addtail(L, x);
			break;
		}
		case 2:
		{
			cin >> x>>y;
			addafter(L, x,y);
			break;
		}
		case 3:
		{
			cin >> x;
			deleteEle(L, x);
			break;
		}
		case 5:
		{
			deletehead(L);
			break;
		}
		case 6: 
		{
			return;
		}
		}
	}
}
void outputList(List& L)
{
	Node* p = L.head;
	if (!p) cout << "Blank";
	while (p!=NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
}
int main()
{
	List L;
	InitList(L);
	inputList(L);
	outputList(L);
}