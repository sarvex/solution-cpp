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
    bool isSymmetric(TreeNode* root) {
        function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* root1, TreeNode* root2) -> bool {
            if (not root1 and not root2) return true;
            if (not root1 or not root2 or root1->val != root2->val) return false;
            return dfs(root1->left, root2->right) and dfs(root1->right, root2->left);
        };
        return dfs(root, root);
    }
};