
#include <iostream>
#include<stack>
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

    void preOrder(Node* root)
    {
        if (root == NULL) return;
        cout << root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
    Node* insert(Node* root, int data)
    {
        stack<Node*> st1,st2;
        st1.push(root);
        while (!st1.empty())
        {
            Node* current = st1.top();
            st2.push(current);
            st1.pop();
            if (current->left)
            {
                st1.push(current->left);
                current = current->left;
            }
            if (current->right)
            {
                st1.push(current->right);
                current = current->right;
            }
        }
        while (!st2.empty())
        {
            cout << st2.top()->data << " ";
            st2.pop();
        }
    }

    }; //End of Solution

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
