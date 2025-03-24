#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <climits>
#include <vector>
#include <stack>
using namespace std;
struct compare
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	}
};
class Graph
{
	vector<vector<int>> matrix;
	vector<string> dinh;
	map<string, int> index;
public:
	
	void inputgraph(int v)
	{
		dinh.resize(v);
		matrix = vector<vector<int>>(v, vector<int>(v, 0));
		for (int i = 0; i < v; i++)
		{
			cin >> dinh[i];
			index[dinh[i]] = i;
		}
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
				cin >> matrix[i][j];
		}
	}
	
	void Dijktra(int s, int e, int v)
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare > open;
		vector<bool> close(v,false);
		vector<int> d(v, INT_MAX);
		map<int, int> cha;
		d[s] = 0;
		open.push({ 0,s });
		bool found = false;
		int count = 1;
		while (!open.empty())
		{
			int p = open.top().second;
			open.pop();
			if (p == e)
			{
				found = true;
				break;
			}
			if (close[p] == true)
				continue;
			close[p] = true;
			count++;
			for (int q = 0; q < v; q++)
			{
				if (matrix[p][q] > 0 )
				{
					int dnew = d[p] + matrix[p][q];
					if (dnew < d[q])
					{
						d[q] = dnew;
						cha[q] = p;
						open.push({ dnew,q });
					}
				}
			}
		}
		if (!found)
		{
			cout << "-unreachable-\n";
			cout << count - 1<<" " << 0 << endl;
		}
		else
		{
			stack<int> path;
			for (int current = e; current != s; current = cha[current])
			{
				path.push(current);
			}
			path.push(s);
			while (!path.empty())
			{
				cout << dinh[path.top()]<<" ";
				path.pop();
			}
			cout << endl;
			cout << count << " " << d[e] << endl;
		}
	}
	void xuli(int v,int n)
	{
		for (int i = 0; i < n; i++)
		{
			string s, e;
			cin >> s >> e;
			Dijktra(index[s], index[e], v);
		}
	}
};
int main()
{
	Graph G;
	int v, n;
	cin >> v>> n;
	G.inputgraph(v);
	G.xuli(v,n);
	return 0;
}