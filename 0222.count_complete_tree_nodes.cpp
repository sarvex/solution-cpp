struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
  static int depth(const TreeNode* root) {
    int d = 0;
    for (; root; root = root->left) { ++d; }
    return d;
  }

public:
  int countNodes(TreeNode* root) {
    if (not root) return 0;
    const int left = depth(root->left);
    const int right = depth(root->right);
    if (left == right) return (1 << left) + countNodes(root->right);
    return (1 << right) + countNodes(root->left);
  }
};
