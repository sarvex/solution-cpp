#include <functional>
#include <vector>

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
  int averageOfSubtree(TreeNode* root) {
    int result = 0;

    std::function<std::pair<int, int>(TreeNode*)> average = [&] (const TreeNode* node) {
      const auto [left_sum, left_count] = node->left ? average (node->left) : std::make_pair(0, 0);
      const auto [right_sum, right_count] = node->right ? average (node->right) : std::make_pair(0, 0);
      const auto sum = left_sum + right_sum + node->val;
      const auto count = left_count + right_count + 1;
      if (sum / count == node->val) ++result;
      return std::make_pair(sum, count);
    };

    average(root);
    return result;
  }
};
