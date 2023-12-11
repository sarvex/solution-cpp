struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  auto getDecimalValue(ListNode *head) {
    int result = 0;
    for (; head; head = head->next) {
      result = (result << 1) + head->val;
    }
    return result;
  }
};
