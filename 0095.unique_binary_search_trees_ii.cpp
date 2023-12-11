#include <functional>
#include <vector>

using std::function;
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
  auto generateTrees(int n) {
    function<vector<TreeNode *>(int, int)> gen = [&](int left, int right) {
      vector<TreeNode *> result;
      if (left > right) {
        result.push_back(nullptr);
      } else {
        for (int i = left; i <= right; ++i) {
          auto leftTrees = gen(left, i - 1);
          auto rightTrees = gen(i + 1, right);
          for (auto &l : leftTrees) {
            for (auto &r : rightTrees) {
              TreeNode *node = new TreeNode(i, l, r);
              result.push_back(node);
            }
          }
        }
      }
      return result;
    };

    return gen(1, n);
  }
};
