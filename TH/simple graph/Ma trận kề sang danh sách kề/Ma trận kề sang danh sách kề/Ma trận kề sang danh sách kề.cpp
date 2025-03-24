#include <iostream>
#include <vector>
using namespace std;
class Graph
{
public:
	int v;
	vector<vector<int>> a;
	vector<vector<int>> adj;
	void nhap()
	{
		cin >> v;
		a.resize(v + 1, vector<int>(v + 1, 0));
		adj.resize(v + 1);
		for (int i = 1; i <= v; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				cin >> a[i][j];
			}
		}
	}
	void xuly()
	{
		for (int i=1;i<=v;i++)
			for (int j = 1; j <= v; j++)
			{
				if (a[i][j] == 1 && i < j)
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
	}
	void xuat()
	{
		for (int i = 1; i <= v; i++) {
			if (!adj[i].empty()) {
				cout << i << "->";
				for (int x : adj[i]) {
					cout << x << " ";
				}
				cout << endl;
			}
		}
	}
};
int main()
{
	int m, n;
	Graph G;
	G.nhap();
	G.xuly();
	G.xuat();
	return 0;
}