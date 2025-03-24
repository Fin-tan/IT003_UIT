#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void BFS(int start, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> open;
    open.push(start);
    visited[start] = true;
   
    while (!open.empty()) {
        int current = open.front();
        open.pop();

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                open.push(neighbor);
            }
        }
    }
}

int main() 
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> adjList(m+1);

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(m+1, false);
    int d;
    cin >> d;
    int count= 0;
    BFS(d, adjList, visited);
    bool found = false;
    for (int i = 1; i <= m; i++) {
        if (visited[i])
        {
            found = true; 
            count++;
            
        }
    }
    cout << count << endl;
    for (int i = 1; i <=m ; i++) {
        if (visited[i])
        {
            found = true;
            count++;
            cout << i << " ";
        }
    }

    return 0;
}