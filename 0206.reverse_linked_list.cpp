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
  ListNode* reverseList(ListNode* head) {
    ListNode result{};
    auto node = head;
    while (node) {
      const auto next = node->next;
      node->next = result.next;
      result.next = node;
      node = next;
    }
    return result.next;
  }
};
