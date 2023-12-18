#include <functional>
#include <vector>

using std::function;
using std::vector;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
  auto sortedListToBST(ListNode *head) {
    vector<int> nums;

    function<TreeNode *(const int, const int)> build =
        [&](const int start, const int end) -> TreeNode*{
          if (start > end) {
            return nullptr;
          }
          int mid = (start + end) / 2;
          TreeNode *root = new TreeNode(nums[mid]);
          root->left = build(start, mid - 1);
          root->right = build(mid + 1, end);
          return root;
        };

    for (; head != nullptr; head = head->next) {
      nums.push_back(head->val);
    }
    return build(0, nums.size() - 1);
  }
};
