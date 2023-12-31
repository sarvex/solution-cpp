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
  int rangeSumBST(const TreeNode* root, const int low, const int high) {
    if (! root) return 0;
    if (low <= root->val and root->val <= high)
      return root->val + (root->left ? rangeSumBST(root->left, low, high) : 0)
             + (root->right ? rangeSumBST(root->right, low, high) : 0);

    if (root->val < low) return root->right ? rangeSumBST(root->right, low, high) : 0;
    return root->left ? rangeSumBST(root->left, low, high) : 0;
  }
};
