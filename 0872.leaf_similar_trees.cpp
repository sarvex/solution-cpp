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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    std::function<std::vector<int>(TreeNode*)> leaf = [&](const TreeNode* node) -> std::vector<int> {
      if (not node) return {};
      auto result = leaf(node->left);
      auto right = leaf(node->right);
      result.insert(result.end(), right.begin(), right.end());
      if (result.empty()) result.push_back(node->val);
      return result;
    };
    return leaf(root1) == leaf(root2);
  }
};
