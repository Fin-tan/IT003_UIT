#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class graph
{
	map<string, int> adj;
	vector<string> dinh ;
	vector<vector<int>> a;

public:
	
	void Nhap(int v,int n)
	{
		a.resize(v, vector<int>(v, 0));
		dinh.resize(v);
		for (int i = 0; i < v; i++)
		{
			cin >> dinh[i];
			adj[dinh[i]] = i;
		}
		for (int i = 0;i < n; i++)
		{
			string x, y;
			cin >> x >> y;
			a[adj[x]][adj[y]] = 1;
			a[adj[y]][adj[x]] = 1;
		}
	}
	void tinhbac()
	{
		for (int i = 0; i < dinh.size(); i++)
		{
			int dem = 0;
			for (int j = 0; j < dinh.size(); j++)
				if (a[i][j] == 1) dem = dem + a[i][j];
			cout << dem << " ";
		}
		
	}
};
int main()
{
	int v,n;
	cin >> v >> n;
	graph G;
	G.Nhap(v, n);
	G.tinhbac();
	return 0;
}