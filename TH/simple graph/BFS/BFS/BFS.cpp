#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;
map<string, int> indexMap;
map<string, string> parent;
void BFS(string start, string goal, int v, const vector<vector<int>>& matrix, const vector<string>& vertices) {
    queue<string> open;
    vector<bool> visited(v, false);
    vector<bool> close(v, false);

    open.push(start);
    visited[indexMap[start]] = true;

    bool found = false;
    int pathLength = 0;
    int nodesExpanded = 0;

    while (!open.empty()) {
        string current = open.front();
        open.pop();
        if (close[indexMap[current]]) continue;
        close[indexMap[current]] = true;
        nodesExpanded++;
        if (current == goal) {
            found = true;
            break;
        }
        for (int i = 0; i < v; i++) {
            if (matrix[indexMap[current]][i] > 0 && !visited[i]) {
                string child = vertices[i];
                open.push(child);
                visited[i] = true;
                if (parent.find(child) == parent.end()) {
                    parent[child] = current;
                }
            }
        }
    }

    if (!found) {
        cout << "-unreachable-" << endl;
        cout << nodesExpanded << " " << 0 << endl;
    }
    else {
        // Truy vết lại đường đi từ đích về nguồn
        vector<string> path;
        string cur = goal;
        while (cur != start) {
            path.push_back(cur);
            pathLength += matrix[indexMap[parent[cur]]][indexMap[cur]];
            cur = parent[cur];
        }
        path.push_back(start);
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i > 0) cout << " ";
        }
        cout << endl;
        cout << nodesExpanded << " " << pathLength << endl;
    }
}

int main() {
    int v, n;
    cin >> v >> n;
    vector<string> vertices(v);
    for (int i = 0; i < v; i++) {
        cin >> vertices[i];
        indexMap[vertices[i]] = i;
    }
    vector<vector<int>> matrix(v, vector<int>(v));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        string start, goal;
        cin >> start >> goal;
        parent.clear();
        BFS(start, goal, v, matrix, vertices);
    }

    return 0;
}