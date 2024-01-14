#include <functional>
#include <limits>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() :
    val(0), left(nullptr), right(nullptr) {}

  explicit TreeNode(const int x) :
    val(x), left(nullptr), right(nullptr) {}

  TreeNode(const int x, TreeNode* left, TreeNode* right) :
    val(x), left(left), right(right) {}
};

class Solution {
public :
  int goodNodes(TreeNode* root) {
    int result = 0;
    const std::function<void(TreeNode*, int)> search = [&](TreeNode* node, int mx) {
      if (mx <= node->val) {
        ++result;
        mx = node->val;
      }
      if (node->left) search(node->left, mx);
      if (node->right) search(node->right, mx);
    };
    if (root) search(root, root->val);
    return result;
  }
};
