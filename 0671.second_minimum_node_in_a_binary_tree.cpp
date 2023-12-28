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
    int result = -1;

    int findSecondMinimumValue(TreeNode* root) {
        dfs(root, root->val);
        return result;
    }

    void dfs(TreeNode* root, int val) {
        if (!root) return;
        dfs(root->left, val);
        dfs(root->right, val);
        if (root->val > val) result = result == -1 ? root->val : min(result, root->val);
    }
};