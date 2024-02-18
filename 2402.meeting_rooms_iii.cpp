#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
  auto mostBooked(const int n, std::vector<std::vector<int>>& meetings) {
    std::priority_queue<int, std::vector<int>, std::greater<>> idle;
    std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<>> busy;
    for (int i = 0; i < n; ++i) idle.push(i);
    std::vector<int> cnt(n);
    std::ranges::sort(meetings);
    for (auto& v: meetings) {
      const int s = v[0], e = v[1];
      while (! busy.empty() and busy.top().first <= s) {
        idle.push(busy.top().second);
        busy.pop();
      }
      int i = 0;
      if (! idle.empty()) {
        i = idle.top();
        idle.pop();
        busy.emplace(e, i);
      } else {
        auto x = busy.top();
        busy.pop();
        i = x.second;
        busy.emplace(x.first + e - s, i);
      }
      ++cnt[i];
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
      if (cnt[result] < cnt[i]) { result = i; }
    }
    return result;
  }
};
