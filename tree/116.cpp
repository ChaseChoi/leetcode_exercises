/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        connectTwoSubtree(root->left, root->right);
        return root;
    }

private:
    void connectTwoSubtree(Node* leftSubtree, Node* rightSubtree) {
        if (leftSubtree == nullptr) {
            return;
        }
        
        leftSubtree->next = rightSubtree;
        connectTwoSubtree(leftSubtree->left, leftSubtree->right);
        connectTwoSubtree(rightSubtree->left, rightSubtree->right);
        connectTwoSubtree(leftSubtree->right, rightSubtree->left);
    }
};