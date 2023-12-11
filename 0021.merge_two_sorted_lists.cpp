struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(const int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  auto mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode dummy{0};

    ListNode *node = &dummy;

    while (list1 and list2) {
      if (list1->val <= list2->val) {
        node->next = list1;
        list1 = list1->next;
      } else {
        node->next = list2;
        list2 = list2->next;
      }
      node = node->next;
    }
    node->next = list1 ? list1 : list2;

    return dummy.next;
  }
};
