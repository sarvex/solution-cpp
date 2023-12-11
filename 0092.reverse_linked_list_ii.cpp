struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  auto reverseBetween(ListNode *head, int left, int right) {
    if (!head->next or left == right) {
      return head;
    }
    ListNode dummy{0, head};
    ListNode *pre = &dummy;
    for (int i = 0; i < left - 1; ++i) {
      pre = pre->next;
    }
    ListNode *p = pre, *q = pre->next;
    ListNode *node = q;
    for (int i = 0; i < right - left + 1; ++i) {
      ListNode *t = node->next;
      node->next = pre;
      pre = node;
      node = t;
    }
    p->next = pre;
    q->next = node;
    return dummy.next;
  }
};
