#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(const int x) : val(x), next(nullptr) {}
  ListNode(const int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  static ListNode* mergeKLists(const std::vector<ListNode *>& lists) {
    std::priority_queue<ListNode *, std::vector<ListNode *>,
      decltype([](const ListNode* a, const ListNode* b) { return a->val > b->val; })> pq;

    for (auto head: lists) {
      if (head) {
        pq.push(head);
      }
    }
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    while (!pq.empty()) {
      ListNode* node = pq.top();
      pq.pop();
      if (node->next) {
        pq.push(node->next);
      }
      cur->next = node;
      cur = cur->next;
    }
    return dummy->next;
  }
};
