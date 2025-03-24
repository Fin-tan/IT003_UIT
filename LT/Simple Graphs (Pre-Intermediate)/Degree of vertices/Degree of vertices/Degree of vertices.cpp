#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

class Graph {
    map<string, set<string>> adjList;

public:
    void addEdge(const string& u, const string& v) {
        adjList[u].insert(v);
    }

    bool isCompleteDigraph() {
        set<string> vertices;
        for (const auto& pair : adjList) {
            vertices.insert(pair.first);
            for (const string& neighbor : pair.second) {
                vertices.insert(neighbor);
            }
        }

        for (const string& u : vertices) {
            for (const string& v : vertices) {
                if (u != v) {
                    if (adjList[u].count(v) == 0 || adjList[v].count(u) == 0) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    int e;
    cin >> e;
    Graph g;

    for (int i = 0; i < e; i++) {
        string u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.isCompleteDigraph()) {
        cout << "TRUE" << endl;
    }
    else {
        cout << "FALSE" << endl;
    }

    return 0;
}
