#include <limits>
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
  int maxLevelSum(TreeNode* root) {
    std::queue<TreeNode*> q{ { root } };
    int mx = std::numeric_limits<int>::min();
    int result = 0;
    for (int i = 1; not q.empty(); ++i) {
      int sum = 0;
      for (int n = q.size(); n; --n) {
        root = q.front();
        q.pop();
        sum += root->val;
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
      if (mx < sum) mx = sum, result = i;
    }
    return result;
  }
};
