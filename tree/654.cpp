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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }

private:
    TreeNode* dfs(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int max = -1, maxValueIndex;
        for (int i = start; i <= end; ++i) {
            if (nums[i] > max) {
                max = nums[i];  
                maxValueIndex = i;
            }
        }
        
        TreeNode* root = new TreeNode(max);
        root->left = dfs(nums, start, maxValueIndex-1);
        root->right = dfs(nums, maxValueIndex+1, end);
        return root;
    }
};