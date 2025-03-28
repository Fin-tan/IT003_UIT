#include <bits/stdc++.h>
using namespace std;

int count_distinct(const vector<string>& ids) {
    map<string, int> Hash;

    for (const string& id : ids) {
        Hash[id] = 1;
    }

    return Hash.size();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> ids(N);

    for (int i = 0; i < N; i++) cin >> ids[i];

    cout << count_distinct(ids) << endl;

    return 0;
}
