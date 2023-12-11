struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  auto deleteDuplicates(ListNode *head) {
    ListNode *node = head;
    while (node != nullptr and node->next != nullptr) {
      if (node->val == node->next->val) {
        node->next = node->next->next;
      } else {
        node = node->next;
      }
    }
    return head;
  }
};
