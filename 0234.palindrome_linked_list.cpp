struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(const int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    auto slow = head;
    auto fast = head->next;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode* pre = nullptr;
    auto cur = slow->next;
    while (cur) {
      ListNode* t = cur->next;
      cur->next = pre;
      pre = cur;
      cur = t;
    }
    while (pre) {
      if (pre->val != head->val) return false;
      pre = pre->next;
      head = head->next;
    }
    return true;
  }
};
