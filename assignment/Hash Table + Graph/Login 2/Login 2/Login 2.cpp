#include <iostream>
#include <string>
#define NMAX (long long)(1e6 + 7)

using namespace std;
struct Node
{
	string name;
	string password;
	Node* next;
};
struct List
{
	Node* head, * tail;
};
struct Hashtable
{
	int m;
	int n;
	List* Matkhau;
};
int Hash(string& username,int m) 
{
	int hashvalue = 0;
	for (char x : username)
	{
		hashvalue = (hashvalue + x) % m;
	}
	return hashvalue;
}
void init(List& L)
{
	L.head = L.tail = NULL;
}
void creatable(Hashtable& h, int size)
{
	h.m = NMAX;
	h.n = 0;
	h.Matkhau = new List[size];
	for (int i = 0; i < size; i++)
	{
		init(h.Matkhau[i]);
	}
}
void addtail(List& L,string& username, string& password)
{
	Node* p = new Node{ username,password,NULL };
	if (L.head == NULL)
	{
		L.head = L.tail = p;
	}
	else
	{
		L.tail->next = p;
		L.tail = p;
	}
}
void insert(Hashtable& h,string& username, string& password)
{
	int index = Hash(username,h.m);
	addtail(h.Matkhau[index],username, password);
}
void getHistory(Hashtable& h, string& username)
{
	int index = Hash(username,h.m);
	Node* p = h.Matkhau[index].head;
	bool check = false;
	while (p && p->name==username)
	{
		check = true;
		cout << p->password << " ";
		p = p->next;
		
	}
	
	if (!check) cout << "Chua Dang Ky!" << endl; else cout << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N, Q;
	cin >> N >> Q;

	Hashtable h;
	creatable(h, NMAX);

	
	for (int i = 0; i < N; i++) {
		string username, password;
		cin >> username >> password;
		insert(h, username,password);
	}

	for (int i = 0; i < Q; i++) {
		string queryUsername;
		cin >> queryUsername;
		getHistory(h, queryUsername);
	}

	return 0;
}