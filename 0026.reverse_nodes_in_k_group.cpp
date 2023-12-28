struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  ListNode* reverse(ListNode* head) {
    ListNode* pre = nullptr;
    for (auto node = head; node;) {
      const auto temp = node->next;
      node->next = pre;
      pre = node;
      node = temp;
    }
    return pre;
  }

public:
  ListNode* reverseKGroup(ListNode* head, const int k) {
    if (k == 1) return head;

    ListNode dummy{ 0, head };
    for (auto current = &dummy, pre = &dummy; current->next;) {
      for (auto i = 0; i < k and current; ++i) current = current->next;

      if (not current) return dummy.next;

      const auto temp = current->next;
      current->next = nullptr;
      const auto start = pre->next;
      pre->next = reverse(start);
      start->next = temp;
      pre = start;
      current = pre;
    }
    return dummy.next;
  }
};
