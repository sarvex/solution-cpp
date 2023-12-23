#include <functional>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  auto isSymmetric(TreeNode* root) {
    std::function<bool(const TreeNode*, const TreeNode*)> symmetry = [&](const TreeNode* left, const TreeNode* right) {
          if (not left and not right) return true;
          if (not left or not right or left->val != right->val) return false;
          return symmetry(left->left, right->right) and symmetry(left->right, right->left);
        };
    return symmetry(root, root);
  }
};
