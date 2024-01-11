#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
  auto largestRectangleArea(const std::vector<int>& heights) {
    int res = 0;
    const int n = heights.size();
    std::stack<int> stk;
    std::vector<int> left(n, -1);
    std::vector<int> right(n, n);
    for (int i = 0; i < n; ++i) {
      while (not stk.empty() and heights[stk.top()] >= heights[i]) {
        right[stk.top()] = i;
        stk.pop();
      }
      if (not stk.empty())
        left[i] = stk.top();
      stk.push(i);
    }
    for (int i = 0; i < n; ++i)
      res = std::max(res, heights[i] * (right[i] - left[i] - 1));
    return res;
  }
};
