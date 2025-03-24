#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void BFS(int start, int goal, int v, const vector<vector<int>>& adjMatrix, vector<string>& results) {
    queue<int> open;            
    vector<bool> visited(v, false);   

    open.push(start);
    visited[start] = true;

    while (!open.empty()) {
        int current = open.front();
        open.pop();

        if (current == goal) {
            results[goal] = "CO";     
            return;
        }

        for (int i = 0; i < v; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                open.push(i);
                visited[i] = true;
            }
        }
    }

  
    results[goal] = "KHONG";
}

int main() {
    int m, n;
    cin >> m >> n;

   
    vector<vector<int>> adjMatrix(m, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  
    }

  
    vector<string> results(m, "KHONG");
    results[0] = "CO";  

    
    for (int i = 1; i < m; i++) {
        if (results[i] == "KHONG") {
            BFS(0, i, m, adjMatrix, results);
        }
    }

   
    for (int i = 1; i < m; i++) {
        cout << results[i] << endl;
    }

    return 0;
}
