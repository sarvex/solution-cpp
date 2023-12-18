#include <algorithm>

using std::max;

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
  auto maxDepth(const TreeNode *root) {
    if (not root) return 0;
    auto l = root->left ? maxDepth(root->left) : 0;
    auto r = root->right ? maxDepth(root->right) : 0;
    return 1 + max(l, r);
  }
};
