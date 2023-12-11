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
    auto fast = head;
    auto slow = head;

    while (n--) {
      fast = fast->next;
    }

    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }

    const auto temp = slow->next;
    if (temp and temp->next)
      slow->next = temp->next;
    else
      slow->next = nullptr;

    delete temp;
    return head;
  }
};
