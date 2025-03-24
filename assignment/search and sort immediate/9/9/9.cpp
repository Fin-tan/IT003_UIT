#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<pair<string, int>>& a) {
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = 0; j < a.size() - i - 1; j++) {
            if (a[j].second < a[j + 1].second ||
                (a[j].second == a[j + 1].second && a[j].first.length() > a[j + 1].first.length()) ||
                (a[j].second == a[j + 1].second && a[j].first.length() == a[j + 1].first.length() && a[j].first > a[j + 1].first)) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void kiemke2(vector<pair<string, int>>& a, vector<string>& b, int n) {
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < a.size(); j++) {
            if (a[j].first == b[i]) {
                a[j].second++;
                found = true;
                break;
            }
        }
        if (!found) {
            a.push_back({ b[i], 1 });
        }
    }
    bubbleSort(a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<pair<string, int>> a;
    kiemke2(a, b, n);
    for (auto& x : a) {
        cout << x.first << " " << x.second << '\n';
    }
    return 0;
}
