struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (not root or root == p or root == q) return root;
    const auto left = lowestCommonAncestor(root->left, p, q);
    const auto right = lowestCommonAncestor(root->right, p, q);
    if (left and right) return root;
    return left ? left : right;
  }
};
