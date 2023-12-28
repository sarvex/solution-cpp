#include <queue>
#include <vector>

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
  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    if (not root) return result;
    std::queue<TreeNode*> q( {root});
    while (not q.empty()) {
      result.emplace_back(q.back()->val);
      for (int n = q.size(); n; --n) {
        const auto node = q.front();
        q.pop();
        if (node->left) { q.push(node->left); }
        if (node->right) { q.push(node->right); }
      }
    }
    return result;
  }
};
