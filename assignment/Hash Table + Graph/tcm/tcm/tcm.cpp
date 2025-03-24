#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Point {
    int x, y;
};

struct Node {
    Point pos;
    Node* next;
};


struct List {
    Node* head, * tail;
};


struct Hashtable {
    int M; 
    List* table;
};


void initList(List& L) {
    L.head = L.tail = NULL;
}


void createTable(Hashtable& h, int m) {
    h.M = m;
    h.table = new List[m];
    for (int i = 0; i < m; i++) {
        initList(h.table[i]);
    }
}


int hashFunction(char k, int M) {
    return k % M; 
}


Node* getNode(Point pos) {
    Node* p = new Node;
    p->pos = pos;
    p->next = NULL;
    return p;
}


void addTail(List& L, Point pos) {
    Node* p = getNode(pos);
    if (L.head == NULL) {
        L.head = L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}


void addToHashTable(Hashtable& h, char key, Point pos) {
    int index = hashFunction(key, h.M);
    addTail(h.table[index], pos);
}

bool isVirusPresent(const vector<string>& file, const string& virus, Hashtable& h) {
    int index = hashFunction(virus[0], h.M);
    Node* p = h.table[index].head;

    while (p) {
        int x = p->pos.x;
        int y = p->pos.y;
        // So sánh m?u virus v?i n?i dung trong file
        if (y + virus.size() <= file[0].size()) { // Không v??t quá chi?u dài dòng
            bool match = true;
            for (int i = 0; i < virus.size(); i++) {
                if (file[x][y + i] != virus[i]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        p = p->next;
    }
    return false;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

   
    vector<string> file(N);
    for (int i = 0; i < N; i++) {
        cin >> file[i];
    }

  
    Hashtable h;
    createTable(h, 26); 

  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Point pos = { i, j };
            addToHashTable(h, file[i][j], pos);
        }
    }

  
    string result = "";
    for (int i = 0; i < Q; i++) {
        string virus;
        cin >> virus;
        if (isVirusPresent(file, virus, h)) {
            result += "1";
        }
        else {
            result += "0";
        }
    }

  
    cout << result << endl;

    return 0;
}
