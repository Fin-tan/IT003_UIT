#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class graph
{
	map<string, vector<string>> adj;
public:
	void nhap(int e)
	{
		for (int i = 0; i < e; i++)
		{
			string u, j;
			cin >> u >> j;
			adj[u].push_back(j);
		}
	}
	void process(int& n)
	{
	
		for (int i = 0; i < n; i++)
		{
			int type;
			cin >> type;
			string u, v;
			
			if (type == 1)
			{
				cin >> u >> v;
				if (xuli1(u,v)) cout << "TRUE\n"; else cout << "FALSE\n";
			}
			else
			{
				cin >> u;
				cout << xuli2(u) << endl;
			}
			
		}

	}
private:
	bool xuli1(string u, string v)
	{
		if (adj.count(u) == 0) return false;
		else
		{
			for (int i = 0; i < adj[u].size(); i++)
			{
				if (adj[u][i] == v) return true;
			}
		}
		return false;
	}
	int xuli2(string u)
	{
		if (adj.count(u) == 0) return 0;
		else return adj[u].size();
	}

};
int main()
{
	graph G;
	int n, e;
	cin >> e >> n;
	G.nhap(e);
	G.process(n);
	return 0;
}