struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  void flatten(TreeNode* root) {
    while (root) {
      if (root->left) {
        auto temp = root->left;
        while (temp->right) { temp = temp->right; }
        temp->right = root->right;
        root->right = root->left;
        root->left = nullptr;
      }
      root = root->right;
    }
  }
};
