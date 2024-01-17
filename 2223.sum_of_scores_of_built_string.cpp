#include <cstdint>
#include <functional>
#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
  long long sumScores(const std::string& s) {
    const auto n = s.size();
    const std::function<std::vector<long long>()> search = [&]() {
      long long l = 0, r = 0;
      std::vector z(n, 0LL);

      for (long long i = 1; i < n; i++) {
        if (i > r) {
          l = r = i;
          while (r < n and s[r] == s[r - l]) r++;
          z[i] = r - l;
          r--;
        } else {
          const long long idx = i - l;
          if (i + z[idx] <= r) { z[i] = z[idx]; } else {
            l = i;
            while (r < n && s[r] == s[r - l]) r++;
            z[i] = r - l;
            r--;
          }
        }
      }
      return z;
    };

    std::vector<long long> z = search();
    return std::reduce(z.begin(), z.end(), 0LL) + n;
  }
};
