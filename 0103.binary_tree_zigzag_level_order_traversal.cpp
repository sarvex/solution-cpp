#include <algorithm>
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
  auto zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int>> result;
    if (not root) return result;
    std::queue<TreeNode *> q{{root}};
    bool left = true;
    while (!q.empty()) {
      std::vector<int> level;
      for (int n = q.size(); n; --n) {
        const auto node = q.front();
        q.pop();
        level.emplace_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      if (not left) reverse(level.begin(), level.end());
      left = !left;
      result.emplace_back(level);
    }
    return result;
  }
};
