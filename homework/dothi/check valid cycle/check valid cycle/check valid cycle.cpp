#include <iostream>
#include<string>
#include <map>
#include<vector>
using namespace std;
class graph
{
	map<string, map<string, int>> adj;
public:
	void nhap(int e)
	{
		string u, v;
		int x;
		for (int i = 0; i < e; i++)
		{
			cin >> u >> v >> x;
			adj[u][v] = x;
		}
	}
	void xuli(int n)
	{
		for (int i = 0; i < n; i++)
		{
			int dem = 0;
			vector<string> vector;
			string v;
			while (true)
			{
				cin >> v;
				if (v == ".") break;
				vector.push_back(v);
			}
			if (tongduongdi(vector, dem)) cout << dem << endl;
			else cout << "False" << endl;
		}
	}
	bool tongduongdi(vector<string>&vector, int& dem)
	{
		for (int i = 0; i < vector.size() - 1; i++)
		{
			string current = vector[i];
			string next = vector[i + 1];
			if (adj[current].find(next) != adj[current].end())
			{
				dem += adj[current][next];
			}
			else {
				return false;
			}
		}
		return true;
	}
	
};
int main()
{
	graph G;
	int e, n;
	cin >> e >> n;
	G.nhap(e);
	G.xuli(n);
	return 0;
}