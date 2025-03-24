#include <iostream>
#include <string>
using namespace std;
struct Hocsinh
{
	int mssv;
	string name;
	int gioitinh;
	int namsinh;
	float dtb;
};
struct Node
{
	Hocsinh hs;
	Node* next;
};
struct List
{
	Node* head, * tail;
};
void InitList(List& L)
{
	L.head = L.tail = NULL;
}
Node* getNode(Hocsinh x)
{
	Node* p = new Node();
	p->hs = x;
	p->next = NULL;
	return p;
}
struct Hash
{
	int m;
	int n;
	List* bucket;
};
int Hashfunc(Hash& H,int x)
{
	return x % H.m;
}
void initHash(Hash& H)
{
	H.bucket = new List[H.m];
	for (int i = 0; i < H.m; i++)
	{
		InitList(H.bucket[i]);
	}
	H.n = 0;	
}
void addtail(List& L, Node* node)
{
	if (L.head == NULL)
	{
		L.head = L.tail = node;
	}
	else
	{
		L.tail->next = node;
		L.tail = node;
	}
}
void insertList(List& L, Hocsinh x)
{
	Node* p = getNode(x);
	addtail(L, p);
}
bool insertHash(Hash& H,Hocsinh x)
{
	float check = float(H.n + 1) / H.m;
	if (check > 0.7)
	{
		return false;
	}
	int index = Hashfunc(H, x.mssv);
	insertList(H.bucket[index], x);
	H.n++;
	return true;
}
void inputHash(Hash& H,int n)
{
	initHash(H);
	Hocsinh x;
	for (int i = 0; i < n; i++)
	{
		cin >> x.mssv;
		getline(cin>>ws, x.name);
		cin >> x.namsinh;
		cin >> x.gioitinh;
		cin >> x.dtb;
		insertHash(H, x);
	}
}
void  printList(List L)
{
	Node* p = L.head;
	while (p)
	{
		cout << '[' << p->hs.mssv << ",  " << p->hs.name << "  , " << p->hs.gioitinh << ", " << p->hs.namsinh << ", " << p->hs.dtb << "] ";
		p = p->next;
	}
	cout << endl;
}
void printHash(Hash H)
{
	for (int i = 0; i < H.m; i++)
	{
		printList(H.bucket[i]);
	}
}
void searchHash(Hash H, int x)
{
	int index = Hashfunc(H, x);
	Node* p = H.bucket[index].head;
	while (p)
	{
		if (p->hs.mssv == x)
		{
			cout << '[' << p->hs.mssv << ",  " << p->hs.name << "  , " << p->hs.gioitinh << ", " << p->hs.namsinh << ", " << p->hs.dtb << "] ";
			return;
		}
		else p = p->next;
	}
	cout << " khong tim thay ";
}
int main()
{
	Hash H;
	int n;
	cin >> H.m;
	cin >> n;
	inputHash(H, n);
	int x;
	cin >>x ;
	searchHash(H,x);
	return 0;
}