#include <iostream>
#include <cstdlib> // Thêm th? vi?n này ?? s? d?ng nullptr

using namespace std;

struct node {
    int info;
    node* left;
    node* right;
};

typedef node* Tree;

node* getnode(int x) {
    node* p = new node();
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertTree(Tree& T, int x) {
    if (T) {
        if (T->info == x) return;
        if (T->info > x)
            insertTree(T->left, x);
        else
            insertTree(T->right, x);
    }
    else {
        T = getnode(x);
    }
}

// ??m s? nút trong cây
int countNodes(Tree T) {
    if (T == NULL) return 0;
    return 1 + countNodes(T->left) + countNodes(T->right);
}

// Ki?m tra cây có ph?i là cây nh? phân hoàn ch?nh không
bool isCompleteBinaryTree(Tree T, int index, int numberNodes) {
    if (T == NULL) return true; // Cây r?ng là cây hoàn ch?nh
    // N?u ch? s? c?a nút l?n h?n s? nút, cây không hoàn ch?nh
    if (index >= numberNodes) return false;
    // Ki?m tra ?? quy cho các nút con
    return isCompleteBinaryTree(T->left, 2 * index + 1, numberNodes) &&
        isCompleteBinaryTree(T->right, 2 * index + 2, numberNodes);
}

bool checkCompleteBinaryTree(Tree T) {
    int nodeCount = countNodes(T);
    return isCompleteBinaryTree(T, 0, nodeCount);
}

void LNR(Tree T) {
    if (T != NULL) {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

void inputTree(Tree& T) {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertTree(T, x);
    }
}

int main() {
    Tree T = NULL;
    inputTree(T);
    cout << "LNR: ";
    LNR(T);
    bool isComplete = checkCompleteBinaryTree(T);
    if (!isComplete)
        cout << "\nThe tree is not a Complete Binary Tree";
    else
        cout << "\nThe tree is a Complete Binary Tree";
    return 0;
}
