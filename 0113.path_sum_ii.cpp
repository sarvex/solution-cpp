#include <functional>
#include <vector>

using std::function;
using std::vector;

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
  auto pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> result;
    vector<int> t;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *root, int s) {
      if (not root)
        return;
      s -= root->val;
      t.emplace_back(root->val);
      if (not root->left and not root->right and s == 0)
        result.emplace_back(t);
      dfs(root->left, s);
      dfs(root->right, s);
      t.pop_back();
    };
    dfs(root, targetSum);
    return result;
  }
};
