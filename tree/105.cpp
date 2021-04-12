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
    	return buildSubtree(preorder, inorder, 0, preorder.size()-1, 0);
    }

private:
	TreeNode* buildSubtree(vector<int>& preorder, vector<int>& inorder, int start, int end, int rootIndex) {
		if (start > end) {
			return nullptr;
		}
		TreeNode* root = new TreeNode(preorder[rootIndex]);
		int current = start;
		while (inorder[current] != preorder[rootIndex]) {
			++current;
		}
		root->left = buildSubtree(preorder, inorder, start, current-1, rootIndex+1);
		root->right = buildSubtree(preorder, inorder, current+1, end, rootIndex+current-start+1);
		return root;
	}
};