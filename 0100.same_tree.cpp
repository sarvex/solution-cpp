struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  auto isSameTree(TreeNode* p, TreeNode* q) {
    if (p == q)
      return true;
    if (not p or not q or p->val != q->val)
      return false;
    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
  }
};
