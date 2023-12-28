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
    auto pre = &dummy;
    for (int i = 0; i < left - 1; ++i) {
      pre = pre->next;
    }

    const auto start = pre, end = pre->next;
    auto node = end;
    for (int i = 0; i < right - left + 1; ++i) {
      const auto temp = node->next;
      node->next = pre;
      pre = node;
      node = temp;
    }
    start->next = pre;
    end->next = node;
    return dummy.next;
  }
};
