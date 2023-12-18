#include <functional>
#include <vector>

using std::function;
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  auto sortedArrayToBST(const vector<int> &nums) {
    function<TreeNode *(int, int)> binary = [&](int l, int r) -> TreeNode * {
      if (l > r) {
        return nullptr;
      }
      int mid = (l + r) >> 1;
      auto left = binary(l, mid - 1);
      auto right = binary(mid + 1, r);
      return new TreeNode(nums[mid], left, right);
    };
    return binary(0, nums.size() - 1);
  }
};
