#include<iostream>
using namespace std;

int main()
{
	int v, e, n;
	cin >> v >> e >> n;

	bool** G; 
	int x, y, nn;
G = new bool* [v];
for (int i = 0; i < v; i++) G[i] = new bool[v] {0};
for (int i = 0; i < e; i++)
{
	cin >> x >> y;
	G[x - 1][y - 1] = 1;
	G[y - 1][x - 1] = 1;
}
for (int i = 0; i < v; i++)
{
	for (int j = 0; j < v; j++)
		cout << G[i][j] << " ";
	cout << endl;
}
for (int i = 0; i < n; i++)
{
	cin >> nn;

	if (nn == 1)
	{
		cin >> x >> y;
		if (G[x - 1][y - 1] == 1) cout << "TRUE\n"; else cout << "FALSE\n";
	}
	else if (nn == 2)
	{
		cin >> x;
		bool check = false;
		for (int i = 0; i < v; i++)
		{
			if (G[x - 1][i] == 1)
			{
				cout << i + 1 << " ";
				check = true;
			}
		}
		if (!check)
			cout << "NONE";
		cout << endl;
	}

}
for (int i = 0; i < v; i++) delete[] G[i];
delete[] G;
return 0;
}