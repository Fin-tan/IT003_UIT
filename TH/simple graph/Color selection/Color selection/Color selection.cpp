#include <map>
#include <set>
#include <vector>
#include <iostream>
#include<string>
using namespace std;

int main() {
    // ??c ??u vào
    int v, e, n;
    cin >> v >> e >> n;

    vector<string> vertices(v);
    map<string, int> vertex_index;
    for (int i = 0; i < v; ++i) {
        cin >> vertices[i];
        vertex_index[vertices[i]] = i; // G?n index cho m?i ??nh
    }

    vector<vector<int>> adj(v); // Danh sách k?
    for (int i = 0; i < e; ++i) {
        string u, w;
        cin >> u >> w;
        int u_idx = vertex_index[u], w_idx = vertex_index[w];
        adj[u_idx].push_back(w_idx);
        adj[w_idx].push_back(u_idx);
    }

    vector<int> colors(v);
    for (int i = 0; i < v; ++i) {
        cin >> colors[i];
    }

    vector<string> query_vertices(n);
    for (int i = 0; i < n; ++i) {
        cin >> query_vertices[i];
    }

    
    for (const string& vertex : query_vertices) {
        int idx = vertex_index[vertex];
        int current_color = colors[idx];

    
        set<int> neighbor_colors;
        for (int neighbor : adj[idx]) {
            if (colors[neighbor] != -1) {
                neighbor_colors.insert(colors[neighbor]);
            }
        }

      
        if (current_color != -1 && neighbor_colors.find(current_color) == neighbor_colors.end()) {
            cout << "TRUE" << endl;
        }
        else {
           
            int new_color = 0;
            while (neighbor_colors.find(new_color) != neighbor_colors.end()) {
                ++new_color;
            }
            cout << new_color << endl;
        }
    }

    return 0;
}
