#include <queue>
#include <stack>
#include <vector>

class Solution {
public:
  auto secondGreaterElementFast(std::vector<int>& nums) {
    const auto n = nums.size();
    std::vector<int> result(n, -1), stk1, stk2, buf;
    for (int i = 0; i < n; i++) {
      while (not stk2.empty() and nums[stk2.back()] < nums[i]) {
        result[stk2.back()] = nums[i];
        stk2.pop_back();
      }
      while (not stk1.empty() and nums[stk1.back()] < nums[i]) {
        buf.push_back(stk1.back());
        stk1.pop_back();
      }
      while (not buf.empty()) {
        stk2.push_back(buf.back());
        buf.pop_back();
      }
      stk1.push_back(i);
    }
    return result;
  }

  auto secondGreaterElement(const std::vector<int>& nums) {
    const auto n = nums.size();
    std::stack<int> stk;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> queue;
    std::vector result(n, -1);
    for (int i = 0; i < n; ++i) {
      const int v = nums[i];
      while (not queue.empty() and queue.top().first < v) {
        result[queue.top().second] = v;
        queue.pop();
      }
      while (not stk.empty() and nums[stk.top()] < v) {
        queue.emplace(nums[stk.top()], stk.top());
        stk.pop();
      }
      stk.push(i);
    }
    return result;
  }
};
