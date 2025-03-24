#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> get_ans(const vector<int>& A, int K) {
        map<int, int> freq; 
        for (int color : A) {
            freq[color]++;
        }

        vector<int> uniqueColors;  
        for (auto& entry : freq) {
            uniqueColors.push_back(entry.first);
        }

        vector<int> result;  

       
        for (int i = 0; i < uniqueColors.size() && result.size() < K; i++) {
            result.push_back(uniqueColors[i]);
            freq[uniqueColors[i]]--; 
        }

    
        for (auto& entry : freq) {
            while (entry.second > 0 && result.size() < K) {
                result.push_back(entry.first);
                entry.second--; 
            }
        }

        return result;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans = get_ans(a, k);

    for (const int& x : ans) cout << x << ' ';
    return 0;
}
