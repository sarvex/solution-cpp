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
  auto isValidBST(TreeNode *root) {
    TreeNode *prev = nullptr;

    function<bool(TreeNode *)> dfs = [&](TreeNode *node) {
      if (!node)
        return true;
      if (!dfs(node->left))
        return false;
      if (prev and prev->val >= node->val)
        return false;
      prev = node;
      if (!dfs(node->right))
        return false;
      return true;
    };
    return dfs(root);
  }
};
