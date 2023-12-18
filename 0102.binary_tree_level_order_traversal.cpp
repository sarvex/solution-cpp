#include <queue>
#include <vector>

using std::queue;
using std::vector;

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
    vector<vector<int>> result;
    if (!root)
      return result;
    queue<TreeNode *> q{{root}};
    while (!q.empty()) {
      vector<int> t;
      for (int n = q.size(); n; --n) {
        auto node = q.front();
        q.pop();
        t.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      result.push_back(t);
    }
    return result;
  }
};
