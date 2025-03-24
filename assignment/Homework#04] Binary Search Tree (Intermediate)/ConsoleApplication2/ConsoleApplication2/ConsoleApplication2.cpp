
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

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();

            cout << current->data << " ";

            
            if (current->right) {
                s.push(current->right);
            }
            if (current->left) {
                s.push(current->left);
            }
        }
    }
    Node* insert(Node* root, int data)
    {
        if (root == NULL) return new Node(data);
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
                else
                {
                    current = current->left;
                }
            }
            else
            {
                if (current->right == NULL)
                {
                    current->right = new Node(data);
                    
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
       }
        return root;
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
