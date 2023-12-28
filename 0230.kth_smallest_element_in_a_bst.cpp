#include <stack>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(const int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> stk;
    while (root or not stk.empty()) {
      if (root) {
        stk.push(root);
        root = root->left;
      } else {
        root = stk.top();
        stk.pop();
        if (--k == 0) return root->val;
        root = root->right;
      }
    }
    return 0;
  }
};
