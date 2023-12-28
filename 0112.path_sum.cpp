#include <functional>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    std::function<bool(TreeNode*, int)> sum = [&](const TreeNode* node, int target) {
      if (not node) return false;
      target += node->val;
      if (not node->left and not node->right and target == targetSum) return true;
      return (node->left ? sum(node->left, target) : false) or (node->right ? sum(node->right, target) : false);
    };
    return sum(root, 0);
  }
};
