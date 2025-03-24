#include<bits/stdc++.h>

using namespace std;

void BFS(string x, string z, vector<string>& vertices, map<string, int>& H, vector<vector<int>>& matrix) {
    queue<string> open;
    open.push(x);
    vector<bool> close(vertices.size(), 0);
    vector<bool> visited(vertices.size(), 0);
    visited[H[x]] = 1;
    bool found = false;
    map<string, string> parent;
    string p;
    
    int countNode = 0, length = 0;

    while (!open.empty()) {
        p = open.front();
        open.pop();

        countNode++;
        
        if (p == z) {
            found = true;
            break;
        }
     
        close[H[p]] = 1;

        for (int i = 0; i < vertices.size(); i++) {
            if ((matrix[H[p]][i] > 0) && (!visited[i])) {
                open.push(vertices[i]);
                visited[i] = 1;
                parent[vertices[i]] = p;
            } 
        }
    }

    if (found) {
        vector<string> road;
        p = z;

        while (p != x) {
            road.push_back(p);
            length += matrix[H[parent[p]]][H[p]];
            p = parent[p];
        }
        road.push_back(x);

        for (int i = road.size() - 1; i >= 0; i--) {
            cout << road[i] << " ";
        }
        cout << "\n";
        cout << countNode << " " << length << "\n";

    } else {
        cout << "-unreachable-\n";
        cout << countNode << " " << 0 << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<string> vertices;
    
    map<string, int> H;
    int v, n;
    cin >> v >> n;

    vector<vector<int>> matrix;
    matrix.resize(v);
    for (int i = 0; i < v; i++) {
        matrix[i].resize(v);
    }

    string x, z;
    int y;

    for (int i = 0; i < v; i++) {
        cin >> x;
        vertices.push_back(x);
        H[vertices[i]] = i;
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> y;
            matrix[i][j] = y;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> x >> z;
        BFS(x, z, vertices, H, matrix);
    }

    return 0;
}