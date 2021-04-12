// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/1130591/2-Solution-or-Detailed-Explanation-with-Code
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	unordered_map<int, int> record;
    	for (int i = 0; i < inorder.size(); ++i) {
    		record[inorder[i]] = i;
    	}
    	return buildSubtree(preorder, inorder, record, 0, preorder.size()-1, 0);
    }

private:
	TreeNode* buildSubtree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& record, int start, int end, int rootIndex) {
		if (start > end) {
			return nullptr;
		}
		TreeNode* root = new TreeNode(preorder[rootIndex]);
		int inorderRootIndex = record[preorder[rootIndex]];
		root->left = buildSubtree(preorder, inorder, record, start, inorderRootIndex-1, rootIndex+1);
		root->right = buildSubtree(preorder, inorder, record, inorderRootIndex+1, end, rootIndex+inorderRootIndex-start+1);
		return root;
	}
};