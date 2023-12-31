#include <functional>
#include <sstream>
#include <string>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  explicit TreeNode(int x) :
    val(x), left(NULL), right(NULL) {}
};

class Codec {

public:
  std::string serialize(TreeNode* root) {
    if (not root) return "";

    std::ostringstream stream;
    std::function<void(TreeNode*)> encode = [&](const TreeNode* node) {
      if (not node)
        stream << "# ";
      else {
        stream << std::to_string(node->val) << " ";
        encode(node->left);
        encode(node->right);
      }
    };

    encode(root);
    return stream.str();
  }

  TreeNode* deserialize(const std::string& data) {
    if (data.empty()) return nullptr;
    std::istringstream stream(data);

    std::function<TreeNode*()> decode = [&]() -> TreeNode* {
      std::string first;
      stream >> first;
      if (first == "#") return nullptr;
      auto* node = new TreeNode(stoi(first));
      node->left = decode();
      node->right = decode();
      return node;
    };

    return decode();
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
