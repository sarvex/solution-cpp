#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
  auto maximalRectangle(const std::vector<std::vector<char>>& matrix) {
    const int n = matrix[0].size();
    std::vector<int> heights(n);
    int result = 0;

    const auto largest = [&]() {
      int res = 0;
      const int m = heights.size();
      std::stack<int> stk;
      std::vector left(m, -1);
      std::vector right(m, m);
      for (int i = 0; i < m; ++i) {
        while (! stk.empty() and heights[stk.top()] >= heights[i]) {
          right[stk.top()] = i;
          stk.pop();
        }
        if (! stk.empty())
          left[i] = stk.top();
        stk.push(i);
      }
      for (int i = 0; i < m; ++i)
        res = std::max(res, heights[i] * (right[i] - left[i] - 1));
      return res;
    };

    for (auto& row: matrix) {
      for (int j = 0; j < n; ++j) {
        if (row[j] == '1')
          ++heights[j];
        else
          heights[j] = 0;
      }
      result = std::max(result, largest());
    }
    return result;
  }
};
