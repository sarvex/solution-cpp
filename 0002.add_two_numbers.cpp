struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(const int x) : val(x), next(nullptr) {}
  ListNode(const int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  auto addTwoNumbers(const ListNode* l1, const ListNode* l2) {
    const int decimal = 10;

    ListNode result{0};
    auto node = &result;

    auto carry = 0;

    while (l1 or l2 or carry) {

      const auto sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = sum / decimal;

      node->next = new ListNode(sum % decimal);
      node = node->next;

      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }

    return result.next;
  }
};
