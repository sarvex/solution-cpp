#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int findMaximizedCapital(int k, int w, const std::vector<int>& profits, const std::vector<int>& capital) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q1;
    const int n = profits.size();
    for (int i = 0; i < n; ++i) { q1.emplace(capital[i], profits[i]); }
    std::priority_queue<int> q2;
    while (k--) {
      while (not q1.empty() and q1.top().first <= w) {
        q2.push(q1.top().second);
        q1.pop();
      }
      if (q2.empty()) { break; }
      w += q2.top();
      q2.pop();
    }
    return w;
  }
};
