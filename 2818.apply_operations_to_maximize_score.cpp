#include <algorithm>
#include <stack>
#include <unordered_set>
#include <vector>

class Solution {
public:
  [[nodiscard]] auto maximumScore(const std::vector<int>& nums, int k) const {
    constexpr int mod = 1e9 + 7;
    const int n = static_cast<int>(nums.size());
    std::vector<std::tuple<int, int, int>> arr(n);

    auto prime_factors = [](int num) {
      int i = 2;
      std::unordered_set<int> result;
      while (i <= num / i) {
        while (num % i == 0) {
          result.insert(i);
          num /= i;
        }
        ++i;
      }
      if (num > 1) result.insert(num);
      return static_cast<int>(result.size());
    };

    auto qpow = [&](long long a, int num) {
      long long result = 1;
      for (; num; num >>= 1) {
        if (num & 1) { result = result * a % mod; }
        a = a * a % mod;
      }
      return result;
    };

    for (int i = 0; i < n; ++i) arr[i] = { i, prime_factors(nums[i]), nums[i] };
    std::vector left(n, -1), right(n, n);
    std::stack<int> stk;
    for (auto [i, f, _]: arr) {
      while (not stk.empty() and get<1>(arr[stk.top()]) < f) stk.pop();
      if (not stk.empty()) left[i] = stk.top();
      stk.push(i);
    }
    stk = {};
    for (int i = n - 1; ~i; --i) {
      const int f = get<1>(arr[i]);
      while (not stk.empty() and get<1>(arr[stk.top()]) <= f) { stk.pop(); }
      if (not stk.empty()) { right[i] = stk.top(); }
      stk.push(i);
    }
    std::ranges::sort(arr, [](const auto& lhs, const auto& rhs) { return get<2>(rhs) < get<2>(lhs); });
    long long result = 1;

    for (auto [i, _, x]: arr) {
      if (const long long cnt = 1LL * (i - left[i]) * (right[i] - i); cnt <= k) {
        result = result * qpow(x, cnt) % mod;
        k -= cnt;
      } else {
        result = result * qpow(x, k) % mod;
        break;
      }
    }
    return result;
  }
};
