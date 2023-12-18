#include <algorithm>

using std::min;

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
  auto minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    if (!root->left) {
      return 1 + minDepth(root->right);
    }
    if (!root->right) {
      return 1 + minDepth(root->left);
    }
    return 1 + min(minDepth(root->left), minDepth(root->right));
  }
};
