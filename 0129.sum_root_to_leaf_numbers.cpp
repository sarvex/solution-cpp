#include <functional>

using std::function;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int sumNumbers(const TreeNode* root) {
    if (not root) return 0;
    function<int(const TreeNode*, int)> sum = [&](const TreeNode* node, int value) {
      if (not node) return 0;
      value = value * 10 + node->val;
      if (not node->left and not node->right) return value;
      return sum(node->left, value) + sum(node->right, value);
    };
    return sum(root, 0);
  }
};
