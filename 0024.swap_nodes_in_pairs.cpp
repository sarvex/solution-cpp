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
    ListNode dummy {0, head};
    ListNode* pre = &dummy;
    ListNode* node = head;
    while (node and node->next) {
      ListNode* temp = node->next;
      node->next = temp->next;
      temp->next = node;
      pre->next = temp;
      pre = node;
      node = node->next;
    }
    return dummy.next;
  }
};
