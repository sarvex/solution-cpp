#include <algorithm>
#include <functional>
#include <limits>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(const int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int result;
  int prev;

  int getMinimumDifference(TreeNode* root) {
    int result = std::numeric_limits<int>::max(), prev = std::numeric_limits<int>::max();

    std::function<void(TreeNode*)> difference = [&](const TreeNode* node) {
      if (node->left) difference(node->left);
      result = std::min(result, abs(prev - node->val));
      prev = node->val;
      if (node->right) difference(node->right);
    };

    difference(root);
    return result;
  }
};
