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
    if (not head or not head->next) {
      return head;
    }
    ListNode *cur = head;
    int n = 0;
    while (cur) {
      ++n;
      cur = cur->next;
    }
    k %= n;
    if (k == 0) {
      return head;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (k--) {
      fast = fast->next;
    }
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode *ans = slow->next;
    slow->next = nullptr;
    fast->next = head;
    return ans;
  }
};
