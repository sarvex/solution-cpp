#include <algorithm>
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
  TreeNode* invertTree(TreeNode* root) {
    std::function<void(TreeNode*)> invert = [&](TreeNode* node) {
      std::swap(node->left, node->right);
      if (node->left) invert(node->left);
      if (node->right) invert(node->right);
    };
    if (root) invert(root);
    return root;
  }
};
