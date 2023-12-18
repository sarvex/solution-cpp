#include <algorithm>
#include <functional>

using std::function;
using std::max;

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
  auto isBalanced(TreeNode *root) {
    function<int(TreeNode *)> height = [&](TreeNode *node) {
      if (!node) {
        return 0;
      }
      int l = height(node->left);
      int r = height(node->right);
      if (l == -1 or r == -1 or abs(l - r) > 1) {
        return -1;
      }
      return 1 + max(l, r);
    };

    return height(root) >= 0;
  }
};
