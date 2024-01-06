#pragma GCC optimize ("O3")

#include <functional>
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
  auto sortedArrayToBST(const std::vector<int>& nums) {
    std::function<TreeNode *(int, int)> binary = [&](const int l, const int r) -> TreeNode* {
      if (l > r) return nullptr;
      const int mid = (l + r) >> 1;
      const auto left = binary(l, mid - 1);
      const auto right = binary(mid + 1, r);
      return new TreeNode(nums[mid], left, right);
    };
    return binary(0, nums.size() - 1);
  }
};
