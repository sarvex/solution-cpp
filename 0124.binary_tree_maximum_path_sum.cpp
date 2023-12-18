#include <algorithm>
#include <functional>
#include <limits>

using std::function;
using std::max;
using std::numeric_limits;

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
  auto maxPathSum(TreeNode *root) {
    int result = std::numeric_limits<int>::min();
    function<int(TreeNode *)> path = [&](TreeNode *node) {
      if (not node) return 0;
      const auto left = max(0, node->left ? path(node->left) : 0);
      const auto right = max(0, node->right ? path(node->right) : 0);
      result = max(result, left + right + node->val);
      return node->val + max(left, right);
    };
    path(root);
    return result;
  }
};
