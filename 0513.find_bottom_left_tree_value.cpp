#include <queue>

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
  auto findBottomLeftValue(TreeNode* root) {
    std::queue<TreeNode*> q { { root } };
    int result = 0;
    while (not q.empty()) {
      result = q.front()->val;
      for (int i = static_cast<int>(q.size()); i; --i) {
        const auto node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }
    return result;
  }
};
