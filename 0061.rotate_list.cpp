struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  auto rotateRight(ListNode* head, int k) {
    if (not head or not head->next) return head;
    int count = 0;

    for (auto node = head; node; ++count) {
      node = node->next;
    }

    k %= count;
    if (k == 0) return head;

    auto fast = head;
    auto slow = head;
    while (k--) {
      fast = fast->next;
    }
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }

    const auto result = slow->next;
    slow->next = nullptr;
    fast->next = head;
    return result;
  }
};
