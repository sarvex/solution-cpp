struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  static ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* pre = dummy;
    ListNode* cur = head;
    while (cur and cur->next) {
      ListNode* t = cur->next;
      cur->next = t->next;
      t->next = cur;
      pre->next = t;
      pre = cur;
      cur = cur->next;
    }
    return dummy->next;
  }
};
