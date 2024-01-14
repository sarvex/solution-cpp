#include <algorithm>

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
  auto pairSumFast(ListNode* head) {
    auto slow = head, fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* prev = nullptr,* node = slow,* next = nullptr;
    while (node) {
      next = node->next;
      node->next = prev;
      prev = node;
      node = next;
    }
    int result = 0;
    while (prev) {
      result = std::max(head->val + prev->val, result);
      head = head->next;
      prev = prev->next;
    }
    return result;
  }

  auto pairSum(ListNode* head) {
    auto slow = head;
    auto fast = head->next;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    auto front = head;
    const auto temp = slow->next;
    slow->next = nullptr;

    auto reverse = [](ListNode* list) {
      ListNode dummy{};
      auto node = list;
      while (node) {
        const auto next = node->next;
        node->next = dummy.next;
        dummy.next = node;
        node = next;
      }
      return dummy.next;
    };

    auto back = reverse(temp);
    int result = 0;
    while (front) {
      result = std::max(result, front->val + back->val);
      front = front->next;
      back = back->next;
    }
    return result;
  }
};
