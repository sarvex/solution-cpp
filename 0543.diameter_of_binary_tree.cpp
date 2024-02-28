#include <functional>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  auto diameterOfBinaryTree(TreeNode* root) {
    if (not root) return 0;
    int result = 0;

    const std::function<int(TreeNode*)> search = [&](const TreeNode* node) {
      const int left = node->left ? search(node->left) : 0;
      const int right = node->right ? search(node->right) : 0;
      result = std::max(result, left + right);
      return 1 + std::max(left, right);
    };

    search(root);
    return result;
  }
};
