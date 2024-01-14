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
  TreeNode* searchBST(TreeNode* root, const int val) {
    if (not root or root->val == val) return root;
    return root->val < val ? searchBST(root->right, val) : searchBST(root->left, val);
  }
};
