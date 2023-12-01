#include <functional>
#include <unordered_map>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    int n = preorder.size();
    std::unordered_map<int, int> d;
    for (int i = 0; i < n; ++i) {
      d[inorder[i]] = i;
    }
    std::function<TreeNode *(int, int, int)> dfs = [&](int i, int j,
                                                       int n) -> TreeNode * {
      if (n <= 0) {
        return nullptr;
      }
      int v = preorder[i];
      int k = d[v];
      TreeNode *l = dfs(i + 1, j, k - j);
      TreeNode *r = dfs(i + 1 + k - j, k + 1, n - 1 - (k - j));
      return new TreeNode(v, l, r);
    };
    return dfs(0, 0, n);
  }
};
