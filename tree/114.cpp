/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        traversePreOrder(root);
    }

private:
    TreeNode* lastNode;

    TreeNode* traversePreOrder(TreeNode* current) {
        if (current == nullptr) {
            return nullptr;
        }

        TreeNode* rightSubtree = current->right;
        TreeNode* leftSubtree = current->left;
        lastNode = current;

        current->right = traversePreOrder(current->left);
        current->left = nullptr;
        TreeNode* tempLastNode = lastNode;
        tempLastNode->right = traversePreOrder(rightSubtree);
        return current;
    }
};