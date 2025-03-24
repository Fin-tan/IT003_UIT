#include <iostream>
#include <cstring>
#include <string>
#define M 10
#define NULLKEY -1
using namespace std;

struct Hash {
    int table[M];
};

void initHash(Hash& H) {
    for (int i = 0; i < M; i++) {
        H.table[i] = NULLKEY;
    }
}

int hashFunction(int x) {
    return x % M;
}

void insertHash(Hash& H, int x) {
    int index = hashFunction(x);
    int j = 0;
    while (H.table[(index + j) % M] != NULLKEY) {
        j++;
        if (j == M) {
            cout << "\nBang bam bi day, khong them duoc" << endl;
            return;
        }
    }
    H.table[(index + j) % M] = x;
}

void traverseAllHash(Hash& H) {
    for (int i = 0; i < M; i++) {
        cout << H.table[i] << " ";
    }
    cout << endl;
}

int main() {
    Hash H;
    initHash(H);

    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        insertHash(H, x);
    }

    cout << "\nCreated Hash:" << endl;
    traverseAllHash(H);

    return 0;
}
