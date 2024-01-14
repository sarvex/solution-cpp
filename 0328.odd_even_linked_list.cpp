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
  ListNode* oddEvenList(ListNode* head) {
    if (not head) return nullptr;
    auto node = head;
    auto odd = head->next;
    const auto even = odd;
    while (odd and odd->next) {
      node->next = odd->next;
      node = node->next;
      odd->next = node->next;
      odd = odd->next;
    }
    node->next = even;
    return head;
  }
};
