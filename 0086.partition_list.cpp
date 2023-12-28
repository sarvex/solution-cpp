struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  auto partition(ListNode *head, int x) {
    ListNode l, m;
    ListNode *less = &l;
    ListNode *more = &m;

    for (auto node = head; node; node = node->next) {
      if (node->val < x) {
        less->next = node;
        less = less->next;
      } else {
        more->next = node;
        more = more->next;
      }
    }

    less->next = m.next;
    more->next = nullptr;
    return l.next;
  }
};
