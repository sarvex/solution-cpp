struct ListNode {
  int val;
  ListNode *next;

  ListNode() :
    val(0), next(nullptr) {}

  explicit ListNode(const int x) :
    val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) :
    val(x), next(next) {}
};

class Solution {
public:
  static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;
    while (list1 and list2) {
      if (list1->val <= list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }
    curr->next = list1 ? list1 : list2;
    return dummy->next;
  }
};
