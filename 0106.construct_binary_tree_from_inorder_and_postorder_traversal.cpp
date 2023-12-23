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
  auto buildTree(const std::vector<int>& inorder, const std::vector<int>& postorder) {
    const int n = inorder.size();
    std::unordered_map<int, int> indexes;
    for (int i = 0; i < n; ++i) indexes[inorder[i]] = i;

    std::function<TreeNode* (int, int, int)> traverse = [&](const int i, const int j, const int l) -> TreeNode * {
      if (l <= 0) return nullptr;
      const int value = postorder[j + l - 1];
      const int k = indexes[value];
      return new TreeNode(value, traverse(i, j, k - i), traverse(k + 1, j + k - i, l - k + i - 1));
    };

    return traverse(0, 0, n);
  }
};
