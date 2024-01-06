#include <functional>
#include <queue>
#include <vector>

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
  auto mergeKListsFast(const vector<ListNode*>& lists) -> ListNode* {
    if (lists.empty()) return nullptr;

    const function<ListNode *(ListNode*, ListNode*)>
        merge = [](ListNode* l1, ListNode* l2) {
          ListNode dummy{ 0 };
          ListNode* node = &dummy;

          while (l1 and l2) {
            if (l1->val < l2->val) {
              node->next = l1;
              l1 = l1->next;
            } else {
              node->next = l2;
              l2 = l2->next;
            }
            node = node->next;
          }
          node->next = l1 ? l1 : l2;

          return dummy.next;
        };

    function<ListNode *(int, int)>
        helper = [&](const int start, const int end) {
          if (start == end) return lists[start];
          if (start + 1 == end) return merge(lists[start], lists[end]);
          const auto mid = start + (end - start) / 2;

          ListNode* left = helper(start, mid);
          ListNode* right = helper(mid + 1, end);
          return merge(left, right);
        };

    return helper(0, lists.size() - 1);
  }

  auto mergeKLists(const vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>,
                   decltype([](const ListNode* a, const ListNode* b) { return a->val > b->val; })>
        priority;

    for (auto head: lists) { if (head) { priority.push(head); } }

    ListNode dummy{ 0 };
    ListNode* head = &dummy;
    while (! priority.empty()) {
      ListNode* node = priority.top();
      priority.pop();
      if (node->next) { priority.push(node->next); }
      head->next = node;
      head = head->next;
    }
    return dummy.next;
  }
};
