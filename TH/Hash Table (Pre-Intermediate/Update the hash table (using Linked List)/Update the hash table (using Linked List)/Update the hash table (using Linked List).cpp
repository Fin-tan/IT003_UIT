#include <iostream>
#include <cstring>
#include <string>
#define M 10
#define NULLKEY -1
using namespace std;

struct Hash {
    int table[M];

    Hash() {
        for (int i = 0; i < M; i++) {
            table[i] = NULLKEY;
        }
    }

    int hashFunction(int key) {
        return key % M;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int j = 0;

        while (table[(index + j * j) % M] != NULLKEY && j < M) {
            j++;
        }

        if (j == M) {
            cout << "\nBang bam bi day, khong them duoc";
            return;
        }

        table[(index + j * j) % M] = key;
        cout << "\nInsert " << key;
    }

    void traverse() {
        for (int i = 0; i < M; i++) {
            if (table[i] != NULLKEY) {
                cout << i << " --> " << table[i] << endl;
            }
        }
    }
};

void initHash(Hash& H) {
    for (int i = 0; i < M; i++) {
        H.table[i] = NULLKEY;
    }
}

void insertHash(Hash& H, int key) {
    H.insert(key);
}

void traverseAllHash(Hash& H) {
    H.traverse();
}

int main() {
    Hash H;
    initHash(H);

    int n, x;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x;
        cout << "\nInsert " << x;
        insertHash(H, x);
    }

    cout << "\nCreated Hash:" << endl;
    traverseAllHash(H);

    return 0;
}
