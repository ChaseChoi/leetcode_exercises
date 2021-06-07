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
    int diameterOfBinaryTree(TreeNode* root) {
         maxHeight(root);
         return maxValue
    }

private:
    int maxValue = 0;

    int maxHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);
        maxValue = max(maxValue, left+right);
        return 1 + max(left, right);
    }
};