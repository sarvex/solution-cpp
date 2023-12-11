#include <algorithm>
#include <functional>

using std::function;
using std::swap;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  auto recoverTree(TreeNode *root) {
    TreeNode *prev = nullptr;
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    function<void(TreeNode * root)> dfs = [&](TreeNode *root) {
      if (!root)
        return;
      dfs(root->left);
      if (prev and prev->val > root->val) {
        if (!first)
          first = prev;
        second = root;
      }
      prev = root;
      dfs(root->right);
    };
    dfs(root);
    swap(first->val, second->val);
  }
};
