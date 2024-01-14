#include <functional>
#include <unordered_map>

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
  int pathSum(TreeNode* root, const int targetSum) {
    std::unordered_map<long, int> count;
    count[0] = 1;
    const std::function<int(TreeNode*, long)> search = [&](TreeNode* node, long s) {
      if (not node) return 0;
      s += node->val;
      int result = count[s - targetSum];
      ++count[s];
      result += search(node->left, s) + search(node->right, s);
      --count[s];
      return result;
    };
    return search(root, 0);
  }
};
