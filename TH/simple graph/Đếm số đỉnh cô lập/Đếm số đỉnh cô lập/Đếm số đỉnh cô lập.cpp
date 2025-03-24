#include <iostream>
using namespace std;
class graph
{
public:
	bool** G; 
	int v;   
	int e;     

	graph() : G(nullptr), v(0), e(0) {}

	void nhap()
	{
	
		cin >> v >> e;
		int x, y;
		G = new bool* [v];
		for (int i = 0; i < v; i++) G[i] = new bool[v] {0};
		for (int i = 0; i < e; i++)
		{
			cin >> x >> y;
			G[x][y] = 1;
			G[y][x] = 1;
		}

	}
	void xuly()
	{
		int dem = 0;
		for (int i = 0; i < v; i++)
		{
			int dembac = 0;
			for (int j = 0; j < v; j++)
			{
				if (G[i][j] == 1) dembac++;
			}
			if (!dembac) dem++;
		}
		cout << dem;
	}
};
int main()
{
	int m, n;
	graph G;
	G.nhap();
	G.xuly();
	return 0;
}