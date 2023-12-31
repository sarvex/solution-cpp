#include <numeric>
#include <vector>

class Solution {
  int minDifficultyFast(const std::vector<int>& jobDifficulty, int d) {
    const int n = static_cast<int>(jobDifficulty.size());
    if (n < d) return -1;
    if (n == d) {
      return std::reduce(jobDifficulty.cbegin(), jobDifficulty.cend());
    }

    std::vector<int> result(n);
    result[0] = jobDifficulty[0];
    for (int i = 1; i < n; ++i) { result[i] = std::max(jobDifficulty[i], result[i - 1]); }

    std::vector<int> prev(n);
    std::vector<int> index;
    index.reserve(n);
    for (int i = 1; i < d; ++i) {
      result.swap(prev);
      index.clear();
      for (int j = i; j < n; ++j) {
        int last = 0;
        result[j] = jobDifficulty[j] + prev[j - 1];
        while (not index.empty() and jobDifficulty[index.back()] <= jobDifficulty[j]) {
          last = index.back();
          index.pop_back();
          result[j] = std::min(result[j], result[last] + jobDifficulty[j] - jobDifficulty[last]);
        }
        if (! index.empty()) {
          last = index.back();
          result[j] = std::min(result[j], result[last]);
        }
        index.emplace_back(j);
      }
    }
    return result.back();
  }

public:
  int minDifficulty(const std::vector<int>& jobDifficulty, int d) {
    const int n = jobDifficulty.size();
    std::vector result(n + 1, std::vector(d + 1, 0x3f3f3f3f));
    result[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1, m = std::min(d, i); j <= m; ++j) {
        for (int k = i, mx = 0; k; --k) {
          mx = std::max(mx, jobDifficulty[k - 1]);
          result[i][j] = std::min(result[i][j], result[k - 1][j - 1] + mx);
        }
      }
    }
    return result[n][d] == 0x3f3f3f3f ? -1 : result[n][d];
  }
};
