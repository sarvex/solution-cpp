#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
    const auto n = temperatures.size();
    std::vector result(n, 0);
    std::stack<int> stk;
    for (int i = 0; i < n; ++i) {
      while (not stk.empty() and temperatures[stk.top()] < temperatures[i]) {
        result[stk.top()] = i - stk.top();
        stk.pop();
      }
      stk.push(i);
    }
    return result;
  }
};
