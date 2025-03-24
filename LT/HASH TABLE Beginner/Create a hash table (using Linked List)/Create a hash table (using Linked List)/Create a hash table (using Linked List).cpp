#include <iostream>
using namespace std;

struct node {
    int info;
    node* next;
};

struct List {
    node* head, * tail;
};

struct Hash {
    int m;
    int n;
    float load;
    List* pL;
};

void Init(List& L) {
    L.head = L.tail = NULL;
}


void initHash(Hash& H) {
    H.pL = new List[H.m];
    for (int i = 0; i < H.m; i++) {
        Init(H.pL[i]);
    }
    H.n = 0;
}

node* addnode(int x) {
    node* p = new node;
    if (p == NULL) {
        return NULL;
    }
    p->info = x;
    p->next = NULL;
    return p;
}

void AddHead(List& l, node* node) {
    if (l.head == NULL) {
        l.head = node;
        l.tail = node;
    }
    else {
        node->next = l.head;
        l.head = node;
    }
}

void addAfter(List& l, node* p, node* q) {
    if (q != NULL) {
        p->next = q->next;
        q->next = p;
        if (l.tail == q)
            l.tail = p;
    }
    else
        AddHead(l, p);
}

int hashfunc(int x, Hash H) {
    return x % H.m;
}

void insertList(List& L, int x) {
    node* newele = addnode(x);

    if (L.head == NULL) {
        L.head = L.tail = newele;
    }
    else {
        L.tail->next = newele;
        L.tail = newele;
    }
}

bool insertHash(Hash& H, int x) {
    float currentLoadFactor = (float)(H.n + 1) / H.m;
    if (currentLoadFactor > H.load) {

        return false;
    }

    int idx = hashfunc(x, H);
    insertList(H.pL[idx], x);
    H.n++;
    return true;
}

void traverseList(List L) {
    node* p = L.head;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void traverseAllHash(Hash H) {
    for (int i = 0; i < H.m; i++) {
        cout << "Bucket " << i << ": ";
        traverseList(H.pL[i]);
    }
}

void inputHash(Hash& H, int n) {
    initHash(H);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertHash(H, x);
    }
}

void printHash(Hash H) {
    for (int i = 0; i < H.m; i++) {
        cout << "List " << i << ": ";
        traverseList(H.pL[i]);
    }
}

void searchHash(Hash H, int key) {
    int idx = hashfunc(key, H);
    node* p = H.pL[idx].head;
    int comparisons = 0;
    while (p != NULL) {
        comparisons++;
        if (p->info == key) {
            cout << comparisons << endl;
            return;
        }
        p = p->next;
    }
    cout << "KHONG" << endl;
}
int main() {
    Hash H;
    cin >> H.m >> H.load;
    int n;
    cin >> n;

    inputHash(H, n);
    printHash(H);

    int nkey, key;
    cin >> nkey;

    for (int i = 0; i < nkey; i++) {
        cin >> key;
        searchHash(H, key);
    }



    return 0;
}
