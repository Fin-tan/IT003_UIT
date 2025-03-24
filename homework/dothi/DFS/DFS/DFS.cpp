#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <climits>
using namespace std;

class Graph {
    vector<string> dinh;
    vector<vector<int>> matrandinh;
    map<string, int> vitri;
    int v; // số đỉnh của đồ thị

public:
    void Nhap(int& v, int& n) {
        this->v = v;
        dinh.resize(v);
        matrandinh.resize(v, vector<int>(v));

        // Đọc danh sách các đỉnh
        for (int i = 0; i < v; i++) {
            cin >> dinh[i];
            vitri[dinh[i]] = i;
        }

        // Đọc ma trận kề
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cin >> matrandinh[i][j];
            }
        }

        // Đọc và xử lý các truy vấn
        string vdau, vcuoi;
        for (int i = 0; i < n; i++) {
            cin >> vdau >> vcuoi;
            DFS(vdau, vcuoi);
            cout << endl;
        }
    }

private:
    void DFS(string s, string u) {
        vector<bool> visited(v, false);
        stack<string> stk;
        map<string, string> parent; // Để theo dõi đường đi
        int countDeveloped = 0;
        int totalLength = 0;

        stk.push(s);
        visited[vitri[s]] = true;

        while (!stk.empty()) {
            string current = stk.top();
            stk.pop();
            countDeveloped++;

            if (current == u) {
                // Khi tìm thấy đỉnh đích, in đường đi
                printPath(s, u, parent);
                cout << countDeveloped << " " << calculatePathLength(u, parent) << endl;
                return;
            }

            // Duyệt các đỉnh kề của `current` theo thứ tự danh sách đỉnh
            int currentIndex = vitri[current];
            for (int i = v - 1; i >= 0; i--) {
                int nextIndex = i;
                if (matrandinh[currentIndex][nextIndex] != 0 && !visited[nextIndex]) {
                    string nextNode = dinh[nextIndex];
                    visited[nextIndex] = true;
                    stk.push(nextNode);
                    parent[nextNode] = current; // Theo dõi cha của `nextNode`
                }
            }
        }

        // Nếu không tìm thấy đường đi từ `s` đến `u`
        cout << "-unreachable-" << endl;
        cout << countDeveloped << " 0" << endl;
    }

    // Hàm để in đường đi từ `s` đến `u` dùng thông tin `parent`
    void printPath(string s, string u, map<string, string>& parent) {
        vector<string> path;
        string current = u;

        while (current != s) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(s);

        // In ngược từ `s` đến `u`
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    // Tính tổng độ dài của đường đi từ `s` đến `u`
    int calculatePathLength(string u, map<string, string>& parent) {
        int totalLength = 0;
        string current = u;

        while (parent.find(current) != parent.end()) {
            string prev = parent[current];
            totalLength += matrandinh[vitri[prev]][vitri[current]];
            current = prev;
        }
        return totalLength;
    }
};

int main() {
    Graph G;
    int n, v;
    cin >> v >> n;
    G.Nhap(v, n);
    return 0;
}
