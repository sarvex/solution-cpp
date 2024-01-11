#include <functional>

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
public:
  int maxAncestorDiff(TreeNode* root) {
    int result = 0;
    std::function<void(TreeNode*, int, int)> search = [&](TreeNode* root, int mi, int mx) {
      if (not root) return;
      result = std::max({ result, abs(mi - root->val), abs(mx - root->val) });
      mi = std::min(mi, root->val);
      mx = std::max(mx, root->val);
      if (root->left) search(root->left, mi, mx);
      if (root->right) search(root->right, mi, mx);
    };
    search(root, root->val, root->val);
    return result;
  }
};
