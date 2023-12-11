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
    ListNode dummy {0, head};
    ListNode *pre = &dummy;
    ListNode *node = head;
    while (node) {
      while (node->next and node->next->val == node->val) {
        node = node->next;
      }
      if (pre->next == node) {
        pre = node;
      } else {
        pre->next = node->next;
      }
      node = node->next;
    }
    return dummy.next;
  }
};
