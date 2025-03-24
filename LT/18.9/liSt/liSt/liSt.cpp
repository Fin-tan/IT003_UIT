#include <iostream>
using namespace std;
	struct node
	{
		int infor;
		node* next;// con trỏ trỏ tới node phía sau
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
		L.head = L.tail=NULL;
		while (1)
		{
			cin >> x;
			if (x == 3) break;
			if (x == 0)
			{
				cin >> y;
				addHead(L, y);
			}
		}
		printlist(L);
	}