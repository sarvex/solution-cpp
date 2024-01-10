#include <algorithm>
#include <vector>

class Solution {
public:
  int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
    const int n = profit.size();
    std::vector<std::tuple<int, int, int>> jobs(n);
    for (int i = 0; i < n; ++i) jobs[i] = { endTime[i], startTime[i], profit[i] };
    sort(jobs.begin(), jobs.end());
    std::vector<int> dp(n + 1);
    for (int i = 0; i < n; ++i) {
      auto [_, s, p] = jobs[i];
      int j = std::upper_bound(
                  jobs.begin(),
                  jobs.begin() + i,
                  s,
                  [&](int x, auto& job) -> bool { return x < get<0>(job); }) - jobs.begin();
      dp[i + 1] = std::max(dp[i], dp[j] + p);
    }
    return dp[n];
  }
};
