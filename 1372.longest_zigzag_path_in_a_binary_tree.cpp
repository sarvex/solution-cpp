#include <algorithm>
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
  int longestZigZag(TreeNode* root) {
    int result = 0;

    const std::function<void(TreeNode*, int, int)> search = [&](TreeNode* node, int left, int right) {
      result = std::max({ left, right, result });
      if (node->left) search(node->left, right + 1, 0);
      if (node->right) search(node->right, 0, left + 1);
    };

    if (root) search(root, 0, 0);
    return result;
  }
};
