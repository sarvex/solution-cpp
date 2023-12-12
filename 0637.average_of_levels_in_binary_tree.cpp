#include <functional>
#include <queue>
#include <vector>;

using std::function;
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
  vector<double> averageOfLevelsFast(const TreeNode *const root) {
    vector<int> count{0};
    vector<double> sum{0.0};
    if (not root) return sum;

    function<void(const TreeNode *, const int)> breadth =
        [&](const TreeNode *node, const int level) {
          if (sum.size() <= level) {
            sum.resize(level + 1);
            count.resize(level + 1);
          }

          sum[level] += node->val;
          ++count[level];

          if (node->left) breadth(node->left, level + 1);
          if (node->right) breadth(node->right, level + 1);
        };

    breadth(root, 0);

    for (int i = 0; i < sum.size(); ++i)
      sum[i] /= count[i];

    return sum;
  }

  vector<double> averageOfLevels(TreeNode *root) {
    queue<TreeNode *> level{{root}};
    vector<double> result;
    while (!level.empty()) {
      auto n = level.size();
      double s = 0;
      for (int i = 0; i < n; ++i) {
        root = level.front();
        level.pop();
        s += root->val;
        if (root->left)
          level.push(root->left);
        if (root->right)
          level.push(root->right);
      }
      result.push_back(s / n);
    }
    return result;
  }
};
