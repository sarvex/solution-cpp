#include <stack>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
  std::stack<TreeNode*> stack;
  explicit BSTIterator(TreeNode* root) { for (; root != nullptr; root = root->left) { stack.push(root); } }

  int next() {
    const auto cur = stack.top();
    stack.pop();
    for (auto node = cur->right; node != nullptr; node = node->left) { stack.push(node); }
    return cur->val;
  }

  [[nodiscard]] bool hasNext() const { return ! stack.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
