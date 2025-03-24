#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Graph {
private:
    unordered_map<string, unordered_set<string>> adjList;

public:
    // Thêm đỉnh vào đồ thị
    int  addVertex(const string& vertex) {
        if (adjList.find(vertex) != adjList.end()) {
            cout << "DUP\n";
            return 1;
        }
        else {
            adjList[vertex] = unordered_set<string>();
            return 0;
        }
    }

    // Thêm cạnh vào đồ thị
    void addEdge(const string& u, const string& v) {
        bool addedVertex = false;

        if (adjList.find(u) == adjList.end()) {
            if(addVertex(u));
            addedVertex = true;
        }
        if (adjList.find(v) == adjList.end()) {
            addVertex(v);
            addedVertex = true;
        }

        if (adjList[u].find(v) != adjList[u].end()) {
            cout << "DUP2\n";
        }
        else {
            adjList[u].insert(v);
            if (addedVertex) {
                cout << "ADD2\n";
            }
            else {
                cout << "ADD3\n";
            }
        }
    }

    // Kiểm tra tính kề của 2 đỉnh
    void checkAdjacent(const string& u, const string& v) {
        if (adjList.find(u) != adjList.end() && adjList[u].find(v) != adjList[u].end()) {
            cout << "TRUE\n";
        }
        else {
            cout << "FALSE\n";
        }
    }

    // Tìm các đỉnh lân cận
    void findNeighbors(const string& vertex) {
        if (adjList.find(vertex) != adjList.end()) {
            cout << adjList[vertex].size() << "\n";
        }
        else {
            cout << "0\n";
        }
    }
};

int main() {
    Graph graph;
    string line;

    while (true) {
        getline(cin, line);
        if (line == "0") break;

        int operation = line[0] - '0';
        line = line.substr(2); // Bỏ số và khoảng trắng phía trước
        if (operation == 1) {
            // Thêm đỉnh
           if( !graph.addVertex(line)) cout<<"ADD\n";
        }
        else if (operation == 2) {
            // Thêm cạnh
            size_t spacePos = line.find(' ');
            string u = line.substr(0, spacePos);
            string v = line.substr(spacePos + 1);
            graph.addEdge(u, v);
        }
        else if (operation == 3) {
            // Kiểm tra tính kề
            size_t spacePos = line.find(' ');
            string u = line.substr(0, spacePos);
            string v = line.substr(spacePos + 1);
            graph.checkAdjacent(u, v);
        }
        else if (operation == 4) {
            // Tìm kiếm đỉnh lân cận
            graph.findNeighbors(line);
        }
    }

    return 0;
}
