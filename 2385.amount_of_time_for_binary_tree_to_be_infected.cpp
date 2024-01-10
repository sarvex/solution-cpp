#include <functional> #include <queue> #include <unordered_map> #include <unordered_set>
#include <vector>

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
  int amountOfTimeFast(const TreeNode* root, const int start) {
    int length = 0, indirect = 0;
    std::function<int(TreeNode*)> height = [&](const TreeNode* node) {
      return 1 + std::max(node->right ? height(node->right) : 0, node->left ? height(node->left) : 0);
    };

    std::function<std::pair<bool, int>(const TreeNode* node)> traverse = [&
        ](const TreeNode* node) -> std::pair<bool, int> {
      if (not node) return { false, 0 };
      if (node->val == start) {
        length = std::max(node->left ? height(node->left) : 0, node->right ? height(node->right) : 0);
        return { true, 0 };
      }
      const auto [l_first, l_second] = traverse(node->left);
      const auto [r_first, r_second] = traverse(node->right);
      if (l_first) {
        // target node found in the left subtree
        indirect = std::max(indirect, 1 + l_second + r_second);
        return { true, 1 + l_second };
      }
      if (r_first) {
        indirect = std::max(indirect, 1 + l_second + r_second);
        // target node found in the right subtree
        return { true, 1 + r_second };
      }
      // there is no target in the current tree
      return { false, 1 + std::max(l_second, r_second) };
    };

    traverse(root);
    return std::max(indirect, length);
  }

  auto amountOfTime(const TreeNode* root, const int start) {
    if (not root) return 0;
    std::unordered_map<int, std::vector<int>> g;

    std::function<void(const TreeNode*)> search = [&](const TreeNode* node) {
      if (node->left) {
        g[node->val].push_back(node->left->val);
        g[node->left->val].push_back(node->val);
        search(node->left);
      }
      if (node->right) {
        g[node->val].push_back(node->right->val);
        g[node->right->val].push_back(node->val);
        search(node->right);
      }
    };
    search(root);

    std::queue<int> q{ { start } };
    std::unordered_set<int> seen;
    int result = -1;
    while (q.size()) {
      ++result;
      for (int n = q.size(); n; --n) {
        int i = q.front();
        q.pop();
        seen.insert(i);
        for (int j: g[i]) if (not seen.contains(j)) q.push(j);
      }
    }
    return result;
  }
};
