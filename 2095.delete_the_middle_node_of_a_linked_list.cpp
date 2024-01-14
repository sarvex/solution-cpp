struct ListNode {
  int val;
  ListNode* next;

  ListNode() :
    val(0), next(nullptr) {}

  explicit ListNode(const int x) :
    val(x), next(nullptr) {}

  ListNode(const int x, ListNode* next) :
    val(x), next(next) {}
};

class Solution {
public:
  ListNode* deleteMiddle(ListNode* head) {
    ListNode dummy(0, head);
    auto slow = &dummy;
    auto fast = head;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    const auto temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return dummy.next;
  }
};
