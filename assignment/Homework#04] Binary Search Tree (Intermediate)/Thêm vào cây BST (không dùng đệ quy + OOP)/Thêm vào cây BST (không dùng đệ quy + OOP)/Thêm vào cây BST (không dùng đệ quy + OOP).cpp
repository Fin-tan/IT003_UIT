#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    void preOrder(Node* root) {

        if (root == NULL)
            return;

        std::cout << root->data << " ";

        preOrder(root->left);
        preOrder(root->right);
    }

    /* you only have to complete the function given below.
    Node is defined as

    class Node {
        public:
            int data;
            Node *left;
            Node *right;
            Node(int d) {
                data = d;
                left = NULL;
                right = NULL;
            }
    };

    */

    Node* insert(Node* root, int data) {
        if (root == NULL)
            return new Node(data);
        Node* current = root;
        while (true)
        {
            if (current->data > data)
            {
                if (current->left == NULL)
                {
                    current->left = new Node(data);
                    break;
                }
                else current = current->left;
            }
            else
            {
                if (current->right == NULL)
                {
                    current->right = new Node(data);
                    break;
                }
                else current = current->right;
            }
        }
       
        return root;
    }
};

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);

    return 0;
}