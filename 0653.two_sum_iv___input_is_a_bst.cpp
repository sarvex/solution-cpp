struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  auto exists(const TreeNode *node, const int &target) {
    if (!node) return false;
    if (node->val == target) return true;
    if (node->val > target) return exists(node->left, target);
    return exists(node->right, target);
  }
  auto find(const TreeNode *root, const TreeNode *node, const int &k) {
    if (!node) return false;
    int target = k - node->val;
    if (target != node->val and exists(root, target)) return true;
    return find(root, node->left, k) or find(root, node->right, k);
  }

public:
  auto findTarget(TreeNode *root, int k) { return find(root, root, k); }
};
