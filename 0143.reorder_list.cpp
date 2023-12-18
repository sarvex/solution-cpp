struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  void reorderList(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next and fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* node = slow->next;
    slow->next = nullptr;

    ListNode* previous = nullptr;
    while (node) {
      ListNode* temp = node->next;
      node->next = previous;
      previous = node;
      node = temp;
    }

    ListNode* left = head;
    ListNode* right = previous;
    while (right) {
      ListNode* temp = right->next;
      right->next = left->next;
      left->next = right;
      left = right->next;
      right = temp;
    }
  }
};
