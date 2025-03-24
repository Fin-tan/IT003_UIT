#include <iostream>
using namespace std;

int main() {
    long long a, k, b, m, n;
    cin >> a >> k >> b >> m >> n;

    long long low = 1;
  
        long long high = n / min(a, b) + 1;
    long long result = high;

    while (low <= high) {
        long long mid = (low + high) / 2;

        
        long long trees_cut_team1 = a * (mid - mid / k);
        
        long long trees_cut_team2 = b * (mid - mid / m);

        long long total_trees_cut = trees_cut_team1 + trees_cut_team2;

        if (total_trees_cut >= n) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
   
        cout << result << endl;

    return 0;
}
