struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(const int x) : val(x), next(nullptr) {}
  ListNode(const int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (not head or not head->next) return head;
    auto slow = head;
    auto fast = head->next;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    const auto t = slow->next;
    slow->next = nullptr;
    auto l1 = sortList(head);
    auto l2 = sortList(t);
    ListNode dummy{};
    auto node = &dummy;
    while (l1 and l2) {
      if (l1->val <= l2->val) {
        node->next = l1;
        l1 = l1->next;
      } else {
        node->next = l2;
        l2 = l2->next;
      }
      node = node->next;
    }
    node->next = l1 ? l1 : l2;
    return dummy.next;
  }
};
