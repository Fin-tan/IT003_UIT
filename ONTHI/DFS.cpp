#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

struct CompareNodes {
    bool operator()(pair<int, int> a, pair<int, int> b) {

        if (a.first == b.first) {
            return a.second < b.second;
        }

        return a.first > b.first;
    }
};

void DFS(map<string, int>& H, vector<vector<int>>& matrix, vector<string>& vertices, int v, string s, string g) {
    stack<string> open;
    open.push(s);
    vector<bool> close(v, 0);
    
    bool found = false;
    map<string, string> parent;
    string p;
    int countNode = 0, length = 0;

    while (!open.empty()) {
        p = open.top();
        open.pop();

        if (p == g) {
            found = true;
            break;
        }

        if (!close[H[p]]) {
            countNode++;
        }
        
        close[H[p]] = 1;

        for (int i = 0; i < vertices.size(); i++) {
            if ((matrix[H[p]][i] > 0) && (close[i] == 0)) {
                open.push(vertices[i]);

                parent[vertices[i]] = p;
            } 
        }
    }

    if (found) {
        vector<string> road;
        p = g;

        while (p != s) {
            road.push_back(p);
            if (parent.find(p) != parent.end()) {
                length += matrix[H[parent[p]]][H[p]];
            }
            p = parent[p];
        }
        road.push_back(s);

        for (int i = road.size() - 1; i >= 0; i--) {
            cout << road[i] << " ";
        }
        cout << "\n";
        //cout << countNode  << " " << length << "\n";

    } else {
        cout << "-unreachable-\n";
    }
}

void Dijkstra(vector<vector<int>>& matrix, vector<string>& vertices, int s, int g, int v) {
//     Hàm d(u) lưu trữ độ dài đường đi ngắn nhất từ đỉnh nguồn s đến đỉnh u
// Bước 1: Khởi tạo
//         Open := {s};
//         Close :={};
//          d(s) :=0; 
    bool found = false; //kiem tra co tim thay duong di hay khong
    int countNodes = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareNodes> open; //luu khoang cach va dinh
    open.push({0, s});

    vector<bool> close(v, 0);
    map<int, int> parent;

    vector<int> d(v, INF);
    d[s] = 0;
       
// Bước 2: While (Open ≠ {})
    while (!open.empty()) {

//         2.1 Chọn p thuộc Open có  d(p) nhỏ nhất (xóa p ra khỏi Open).
        //note: neu co nhieu dinh co khoang cach nho nhat thi chon dinh nhap vao cuoi cung trong danh sach dinh
        int p = open.top().second;
        //cout << vertices[p] << " " << open.top().first << "\n";
        open.pop();
//         2.2 Nếu p là đỉnh đích thì xuất đường đi, kết thúc thuật toán
        if (!close[p]) {    
            countNodes++;
        }
        if (p == g) {
            found = true;
            break;
        }

        
//      2.3 Nếu p đã duyệt rồi thì bỏ qua, không xem xét lại, trở lại đầu vòng lặp
        if (close[p]) {
            continue;
        }
        
//         2.4 Đánh dấu p đã duyệt qua rồi (tức thêm p vào Close)
        close[p] = 1;
//         2.5 Mở các đỉnh kế tiếp q sau p (kề với p)
        for (int q = 0; q < v; q++) {
//         Với mỗi đỉnh q kề với p, nếu q không thuộc Close:
            if (matrix[p][q] > 0 && close[q] == 0) {     
                int d_new = d[p] + matrix[p][q];
                if (d_new < d[q]) {
                    d[q] = d_new;
                    parent[q] = p;
                    open.push({d[q], q});
                }
            }
        }        
    }
// Bước 3: Kết luận “Không tìm thấy đường đi”
    if (found) {
        vector<int> path;
        int current = g;
        while (current != s) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(s);

        for (int i = path.size() - 1; i >= 0; i--) {
            cout << vertices[path[i]] << " ";
        }
        
        cout << "\n" << countNodes << " " << d[g] << "\n";
    } else {
        cout << "-unreachable-\n";
        cout << countNodes << " " << 0 << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int v, n;

    string x, y;
    cin >> v >> n;

    map<string, int> H;
    vector<string> vertices;
    vector<vector<int>> matrix;
    matrix.resize(v);
    for (int i = 0; i < v; i++) {
        matrix[i].resize(v);
    }

    for (int i = 0; i < v; i++) {
        cin >> x;
        vertices.push_back(x);
        H[x] = i;
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        DFS(H, matrix, vertices, v, x, y);
    }
    return 0;
}