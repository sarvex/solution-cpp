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
  unordered_map<int, int> indexes;

  auto buildTree(const vector<int> &inorder, const vector<int> &postorder) {
    for (int i = 0; i < inorder.size(); ++i)
      indexes[inorder[i]] = i;

    function<TreeNode *(const int, const int, const int)> traverse =
        [&](const int i, const int j, const int n) -> TreeNode * {
      if (n <= 0)
        return nullptr;
      int v = postorder[j + n - 1];
      int k = indexes[v];
      TreeNode *root = new TreeNode(v);
      root->left = traverse(i, j, k - i);
      root->right = traverse(k + 1, j + k - i, n - k + i - 1);
      return root;
    };

    return traverse(0, 0, inorder.size());
  }
};
