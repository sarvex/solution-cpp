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
    const int inf = INT_MAX;
    int result;
    int prev;

    int minDiffInBST(TreeNode* root) {
        result = inf, prev = inf;
        dfs(root);
        return result;
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        result = min(result, abs(prev - root->val));
        prev = root->val;
        dfs(root->right);
    }
};