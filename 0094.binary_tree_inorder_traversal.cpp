#include <vector>

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
  auto inorderTraversal(const TreeNode *root) {
    vector<int> result;

    if (root == nullptr)
      return result;

    if (root->left) {
      result = inorderTraversal(root->left);
    }
    result.emplace_back(root->val);

    vector<int> temp;
    if (root->right != nullptr) {
      temp = inorderTraversal(root->right);
    }
    result.insert(result.end(), temp.cbegin(), temp.cend());

    return result;
  }
};
