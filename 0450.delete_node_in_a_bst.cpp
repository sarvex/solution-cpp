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
  TreeNode* deleteNode(TreeNode* root, const int key) {
    if (not root) return root;
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
      return root;
    }
    if (root->val < key) {
      root->right = deleteNode(root->right, key);
      return root;
    }
    if (not root->left) return root->right;
    if (not root->right) return root->left;
    auto node = root->right;
    while (node->left) node = node->left;
    node->left = root->left;
    node = root;
    root = root->right;
    delete node;
    return root;
  }
};
