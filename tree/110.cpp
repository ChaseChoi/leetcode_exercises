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
    bool isBalanced(TreeNode* root) {
        return countSubtree(root) != -1;
    }

private:
    int countSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftCount = countSubtree(root->left);
        int rightCount = countSubtree(root->right);
         
        if (leftCount == -1 
            || rightCount == -1
            || abs(leftCount - rightCount) > 1) {
            return -1;
        }

        return 1 + max(leftCount, rightCount);
    }
};