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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return 0;
        return dfs(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }

    bool dfs(TreeNode* root1, TreeNode* root2) {
        if (!root1 and !root2) return 1;
        if (!root1 or !root2) return 0;
        return root1->val == root2->val and dfs(root1->left, root2->left) and dfs(root1->right, root2->right);
    }
};