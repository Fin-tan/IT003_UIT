    #include <iostream>
    using namespace std;

    struct Node {
        int info;
        Node* left;
        Node* right;
    };

    Node* getNode(int x) {
        Node* p = new Node();
        p->info = x;
        p->left = NULL;
        p->right = NULL;
        return p;
    }

    typedef Node* Tree;

    void insertTree(Tree& T, int x) {
        if (T) {
            if (T->info == x) return;
            if (T->info > x) insertTree(T->left, x);
            if (T->info < x) insertTree(T->right, x);
        }
        else {
            T = getNode(x);
        }
    }

    void inputTree(Tree& T) {
        int x;
        while (cin >> x && x != -1) {
            insertTree(T, x);
        }
    }
    int treeHeight(Node* root) {
        if (!root) return 0;
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return max(leftHeight, rightHeight) + 1;
    }


    void printLevel(Node* root, int level) {
        if (!root) return;
        if (level == 1) {
            cout << root->info << " ";
        }
        else if (level > 1) {
            printLevel(root->right, level - 1);
            printLevel(root->left, level - 1);
        }
    }

    // Duyệt cây từ tầng dưới lên trên
    void levelOrderBottomUp(Node* root) {
        int height = treeHeight(root);
        for (int i = height; i >= 1; i--) {
            printLevel(root, i);
        }
    }

    int main() {
        Tree T = NULL;
        inputTree(T);
        levelOrderBottomUp(T);
        return 0;
    }
