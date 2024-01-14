#include <cstdint>
#include <string>
#include <vector>

class Solution {
public:
  auto numberOfArrays(const std::string& s, int k) {
    const auto n = s.size();
    // result[i] := the number of arrays to restore s[i..n) with k
    std::vector<int> result(n + 1);
    result.back() = 1; // an empty string ""

    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '0') continue; // a leading zero
      int64_t num = 0;
      for (int j = i; j < n; ++j) {
        num = num * 10 + (s[j] - '0');
        if (num > k) break;
        result[i] = (result[i] + result[j + 1]) % 1'000'000'007;
      }
    }

    return result[0];
  }
};
