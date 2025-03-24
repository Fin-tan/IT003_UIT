#include <iostream>
#include <vector>
using namespace std;

void inputGraph(vector<vector<bool>>& G, int v, int e)
{
    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        G[x - 1][y - 1] = true;
        G[y - 1][x - 1] = true; // Thêm cạnh ngược lại cho đồ thị vô hướng
    }
}

void process(const vector<vector<bool>>& G, int v, int n)
{
    int nn, x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> nn;

        if (nn == 1) // Kiểm tra tính kề
        {
            cin >> x >> y;
            if (G[x - 1][y - 1])
                cout << "TRUE\n";
            else
                cout << "FALSE\n";
        }
        else if (nn == 2) // Tìm đỉnh kề
        {
            cin >> x;
            bool check = false;
            for (int i = 0; i < v; i++)
            {
                if (G[x - 1][i])
                {
                    cout << i + 1 << " ";
                    check = true;
                }
            }
            if (!check)
                cout << "NONE";
            cout << endl;
        }
    }
}

int main()
{
    int v, e, n;
    cin >> v >> e >> n;

    vector<vector<bool>> G(v, vector<bool>(v, false));

    inputGraph(G, v, e); // Nhập đồ thị
    process(G, v, n);     // Xử lý các thao tác

    return 0;
}
