#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
void BFS(int start, vector<vector<int>>& adj, vector<bool>&visited)
{
	queue<int> open;
	open.push(start);
	visited[start] = true;
	while (!open.empty())
	{
		int current = open.front();
		open.pop();
		for (int neibor : adj[current])
		{
			if (!visited[neibor])
			{
				visited[neibor] = true;
				open.push(neibor);
			}
		}
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> adj(m+1);
	int u, v;
	vector<bool> visited( m + 1,false );
	for (int i = 0; i < n; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int d;
	cin >> d;
	BFS(d, adj, visited);
	for (int i = 1; i <= m; i++)
	{
		if (visited[i])
		{
			cout << i << " ";
		}
	}
	return 0;
}