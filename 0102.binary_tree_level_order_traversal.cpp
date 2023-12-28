#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  auto levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> result;
    if (!root) return result;
    std::queue<TreeNode *> q{{root}};
    while (!q.empty()) {
      std::vector<int> t;
      for (int n = q.size(); n; --n) {
        const auto node = q.front();
        q.pop();
        t.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      result.emplace_back(t);
    }
    return result;
  }
};
