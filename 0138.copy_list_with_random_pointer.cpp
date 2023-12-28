class Node {
public:
  int val;
  Node* next;
  Node* random;

  explicit Node(const int val) {
    this->val = val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (not head) { return nullptr; }
    for (auto current = head; current;) {
      const auto node = new Node(current->val);
      node->next = current->next;
      current->next = node;
      current = node->next;
    }
    for (auto current = head; current; current = current->next->next) {
      if (current->random) { current->next->random = current->random->next; }
    }
    const auto result = head->next;
    for (auto current = head; current;) {
      const auto node = current->next;
      if (node) { current->next = node->next; }
      current = node;
    }
    return result;
  }
};
