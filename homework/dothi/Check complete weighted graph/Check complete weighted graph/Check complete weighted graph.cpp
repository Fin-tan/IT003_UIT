#include <iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
class graph
{
public:
	map<string, set<string>> adj;
	void Nhap(string&u, string& v)
	{
		adj[u].insert(v);
	}
	void xuli()
	{
	
		for (auto& x : adj)
		{
			if (x.second.size() != adj.size()-1)
			{
				cout << "false";
				return;
			}
		}
		cout << "true";
	}
};
int main()
{
	graph G;
	int n;
	string u, v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> u >> v;
		G.Nhap(u, v);
	}
	G.xuli();
	return 0;
}