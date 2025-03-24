#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node* next;
};
struct List
{
	Node* head, * tail;
};
struct Hash
{
	int M;
	int n;
	List* Bucket;
};
void initList(List& L)
{
	L.head = L.tail = NULL;
}
void inithash(Hash& H)
{
	H.Bucket = new List[H.M];
	for (int i = 0; i < H.M; i++)
	{
		initList(H.Bucket[i]);
	}
}
Node* getNode(int x)
{
	Node* p = new Node();
	p->val = x;
	p->next = NULL;
	return p;
}
void addhead(List& L, Node* node)
{
	if (L.head == NULL)
	{
		L.head = L.tail = node;
	}
	else
	{
		node->next = L.head;
		L.head = node;
	}
}
void addaffter(List& L, Node* p, Node* q)
{
	if (q)
	{
		p->next = q->next;
		q->next = p;
		if (L.tail == q)
			L.tail = p;
	}
	else
	{
		addhead(L, p);
	}
}
int Hashfunc(Hash H,int x)
{
	return x % H.M;
}
void insertList(List& L, int x)
{
	Node* newele = getNode(x);
	Node* q = L.head, * p = NULL;
	while (q && x>	q->val)
	{
		p = q;
		q = q->next;
	}
	if (p) addaffter(L, newele, p); else addhead(L, newele);
}
void insertHash(Hash& H,int x)
{
	int index = Hashfunc(H, x);
	insertList(H.Bucket[index], x);
}
void printList(List L)
{
	Node* p = L.head;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
void printHash(Hash H)
{
	for (int i = 0; i < H.M; i++)
	{
		printList(H.Bucket[i]);
	}
}
int main()
{
	Hash H;
	int x;
	cin >> H.M;
	cin >> H.n;
	inithash(H);
	for (int i = 0; i < H.n; i++)
	{
		cin >> x;
		insertHash(H, x);
	}
	printHash(H);
	return 0;
}