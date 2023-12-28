struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(const int x) : val(x), next(nullptr) {}
  ListNode(const int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  auto removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy{0, head};
    auto fast = &dummy;
    while (n--) {
      fast = fast->next;
    }

    auto slow = &dummy;
    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }

    const auto temp = slow->next;
    slow->next = temp->next;
    delete temp;

    return dummy.next;
  }
};
