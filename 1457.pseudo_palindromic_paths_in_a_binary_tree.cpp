#include <functional>

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
    auto pseudoPalindromicPaths(TreeNode* root) {
      std::function<int(TreeNode*, int)> search = [&](TreeNode* node, int mask) {
        if (not node) return 0;
        mask ^= 1 << node->val;
        if (not node->left and not node->right) return (mask & (mask - 1)) == 0 ? 1 : 0;
        return search(node->left, mask) + search(node->right, mask);
      };
      return search(root, 0);
    }
};
