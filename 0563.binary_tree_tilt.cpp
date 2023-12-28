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

    int findTilt(TreeNode* root) {
        result = 0;
        sum(root);
        return result;
    }

    int sum(TreeNode* root) {
        if (!root) return 0;
        int left = sum(root->left), right = sum(root->right);
        result += abs(left - right);
        return root->val + left + right;
    }
};