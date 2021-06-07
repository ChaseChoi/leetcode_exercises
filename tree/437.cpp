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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        return continuousCountStartWith(root, targetSum)
        + pathSum(root->left, targetSum)
        + pathSum(root->right, targetSum);
    }

private:
    int continuousCountStartWith(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        int count = root->val == targetSum ? 1 : 0;
        return count + continuousCountStartWith(root->left, targetSum - root->val)
        + continuousCountStartWith(root->right, targetSum - root->val);
    }
};