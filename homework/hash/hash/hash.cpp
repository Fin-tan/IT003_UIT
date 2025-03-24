#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* next;
};
struct List
{
	Node* head, * tail;
};
struct Hash
{
	int m;
	int count;
	float load;
	List* pL;
};
Node* getNode(int x)
{
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
void Init(List& L)
{
	L.head = L.tail = NULL;
}
void InitHash(Hash& H)
{
	H.pL = new List[H.m];
	for (int i = 0; i < H.m; i++)
	{
		Init(H.pL[i]);
	}
	H.count = 0;
}
void AddHead(List& l, Node* node) {
	if (l.head == NULL) {
		l.head = l.tail = node;
	}
	else {
		node->next = l.head;
		l.head = node;
	}
}

void addAfter(List& l, Node* p, Node* q) {
	if (q != NULL) {
		p->next = q->next;
		q->next = p;
		if (l.tail == q)
			l.tail = p;
	}
	else
		AddHead(l, p);
}
void insertList(List& L, int x)
{
	Node* p = getNode(x);
	if (L.head == NULL) AddHead(L, p);
	else
	{
		L.tail->next = p;
		p->next = NULL;
		L.tail = p;
	}
}
int hashfunc(int x, Hash H)
{
	return x % H.m;
}
bool insertHash(Hash& H,int x)
{
	float loadd = float(H.count + 1) / H.m;
	if (loadd > H.load) return false;
	int idx = hashfunc(x, H);
	insertList(H.pL[idx], x);
	H.count++;
	return true;
}
void traverseList(List L) {
	Node* p = L.head;
	while (p != NULL) {
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}
void printHash(Hash H)
{
	for (int i = 0; i < H.m; i++)
	{
		cout << "Bucket " << i << " : ";
		traverseList(H.pL[i]);
	}
}
void inputHash(Hash& H, int n)
{
	InitHash(H);
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (!insertHash(H, x)) {}
	}
}
int main() {
	Hash H;
	cin >> H.m >> H.load;
	int n;
	cin >> n;

	inputHash(H, n);
	printHash(H);

	

	return 0;
}