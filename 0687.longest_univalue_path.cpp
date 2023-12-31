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
    int result;

    int longestUnivaluePath(TreeNode* root) {
        result = 0;
        dfs(root);
        return result;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        left = root->left and root->left->val == root->val ? left + 1 : 0;
        right = root->right and root->right->val == root->val ? right + 1 : 0;
        result = max(result, left + right);
        return max(left, right);
    }
};