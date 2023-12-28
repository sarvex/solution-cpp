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
  bool isValidBSTFast(TreeNode* root) {
    std::function<bool(TreeNode*, TreeNode*, TreeNode*)> validate = [&](TreeNode* node, TreeNode* low, TreeNode* high) {
      if ((low and node->val <= low->val) or (high and node->val >= high->val)) return false;
      return (node->left ? validate(node->left, low, node) : true) and (node->right ? validate(node->right, node, high) : true);
    };
    return root ? validate(root, nullptr, nullptr) : true;
  }

  auto isValidBST(TreeNode* root) {
    if (not root) return true;
    TreeNode* prev = nullptr;

    std::function<bool(TreeNode*)> valid = [&](TreeNode* node) {
      if ((node->left and not valid(node->left)) or (prev and prev->val >= node->val)) return false;
      prev = node;
      if (node->right and not valid(node->right)) return false;
      return true;
    };

    return valid(root);
  }
};
