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
    function<int(TreeNode *)> dfs = [&](TreeNode *root) {
      if (not root) return 0;
      const auto left = max(0, dfs(root->left));
      const auto right = max(0, dfs(root->right));
      result = max(result, left + right + root->val);
      return root->val + max(left, right);
    };
    dfs(root);
    return result;
  }
};
