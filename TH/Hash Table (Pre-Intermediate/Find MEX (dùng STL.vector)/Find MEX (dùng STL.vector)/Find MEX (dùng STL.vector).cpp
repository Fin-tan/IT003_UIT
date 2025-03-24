#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n];

  
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    int maxValue = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxValue) {
            maxValue = a[i];
        }
    }

    
    vector<int> b(maxValue + 1, 0);

   
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0 && a[i] <= maxValue) {
            b[a[i]] = 1;
        }
    }


    int mex = 0;
    while (mex <= maxValue && b[mex]) {
        mex++;
    }

    
    if (mex > maxValue) {
        cout << maxValue + 1 << endl;
    }
    else {
        cout << mex << endl;
    }

    
    delete[] a;

    return 0;
}
