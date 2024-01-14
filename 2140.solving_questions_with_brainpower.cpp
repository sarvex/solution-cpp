#include <cstdint>
#include <functional>
#include <vector>

class Solution {
public:
  auto mostPointsFast(const std::vector<std::vector<int>>& questions) {
    const auto n = questions.size();
    std::vector result(questions.size(), 0LL);
    result[n - 1] = questions[n - 1][0];

    for (int i = n - 2; i >= 0; i--) {
      result[i] = std::max(result[i], result[i + 1]);
      if (i + questions[i][1] + 1 < n)
        result[i] = std::max(result[i + questions[i][1] + 1] + questions[i][0], result[i]);
      else result[i] = std::max(static_cast<int64_t>(questions[i][0]), result[i]);
    }
    return result[0];
  }

    auto mostPoints(const std::vector<std::vector<int>>& questions)
    {
      const auto n = questions.size();
      std::vector f(n, 0LL);
      std::function<int64_t(int)> search = [&](const int i) -> long long {
        if (i >= n) return 0;
        if (f[i]) return f[i];
        const int p = questions[i][0], b = questions[i][1];
        return f[i] = std::max(p + search(i + b + 1), search(i + 1));
      };
      return search(0);
    }
  };
