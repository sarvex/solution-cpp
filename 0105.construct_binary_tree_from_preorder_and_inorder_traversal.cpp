#include <functional>
#include <unordered_map>
#include <vector>

using std::function;
using std::unordered_map;
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
  auto buildTree(const vector<int> &preorder, const vector<int> &inorder) {
    auto n = preorder.size();
    unordered_map<int, int> d;
    for (int i = 0; i < n; ++i) {
      d[inorder[i]] = i;
    }
    function<TreeNode *(const int, const int, const int)>
      traverse = [&](const int i, const int j, const int n) -> TreeNode * {
      if (n <= 0)
        return nullptr;
      int v = preorder[i];
      int k = d[v];
      TreeNode *l = traverse(i + 1, j, k - j);
      TreeNode *r = traverse(i + 1 + k - j, k + 1, n - 1 - (k - j));
      return new TreeNode(v, l, r);
    };
    return traverse(0, 0, n);
  }
};
