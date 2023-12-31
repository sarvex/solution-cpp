#include <functional>
#include <queue>

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
  bool isCompleteTreeFast(TreeNode* root) {
    std::function<int(TreeNode*)> count = [&](TreeNode* node) {
      return 1 + (node->left ? count(node->left) : 0) + (node->right ? count(node->right) : 0);
    };

    const int nodes = count(root);

    std::function<bool(TreeNode*, int)> solve = [&](const TreeNode* node, const int i) {
      if (i >= nodes) return false;
      return (node->left ? solve(node->left, 2 * i + 1) : true) and (
               node->right ? solve(node->right, 2 * i + 2) : true);
    };

    return root ? solve(root, 0) : true;
  }

  bool isCompleteTree(TreeNode* root) {
    std::queue<TreeNode*> q{ { root } };
    while (q.front()) {
      const auto node = q.front();
      q.pop();
      q.push(node->left);
      q.push(node->right);
    }
    while (not q.empty() and not q.front()) q.pop();
    return q.empty();
  }
};
