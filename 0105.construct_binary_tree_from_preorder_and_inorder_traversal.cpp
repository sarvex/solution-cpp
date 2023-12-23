#include <functional>
#include <unordered_map>
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
  auto buildTree(const std::vector<int> &preorder, const std::vector<int> &inorder) {
    const auto n = preorder.size();
    std::unordered_map<int, int> d;
    for (int i = 0; i < n; ++i) {
      d[inorder[i]] = i;
    }
    std::function<TreeNode *(int, int, int)>
      traverse = [&](const int i, const int j, const int l) -> TreeNode * {
      if (l <= 0) return nullptr;
      const int value = preorder[i];
      const int k = d[value];
      TreeNode *left = traverse(i + 1, j, k - j);
      TreeNode *right = traverse(i + 1 + k - j, k + 1, l - 1 - (k - j));
      return new TreeNode(value, left, right);
    };
    return traverse(0, 0, n);
  }
};
