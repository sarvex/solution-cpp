#include <cstdint>
#include <functional>
#include <string>
#include <vector>

class Solution {
public:
  auto numberOfBeautifulIntegers(const int low, const int high, const int k) {
    std::vector memo(11, std::vector(2, std::vector(22, std::vector(22, -1))));

    const std::function<int(int, bool, int, int, const std::string&)> search = [&
        ](const int len, const bool same, const int diff, const int r, const std::string& num) {
      const auto n = num.size();

      if (len == 0) {
        if (diff == 0 && r == 0) return 1;
        return 0;
      }

      if (memo[len][same][diff + 10][r] != -1)
        return memo[len][same][diff + 10][r];

      int ret = 0;
      if (not same) {
        for (int d = 0; d <= 9; d++)
          ret += search(len - 1, false, diff + (d % 2 == 0) * 2 - 1, (r * 10 + d) % k, num);
      } else {
        const int digit = num[n - len] - '0';
        for (int d = 0; d < digit; d++)
          ret += search(len - 1, false, diff + (d % 2 == 0) * 2 - 1, (r * 10 + d) % k, num);
        ret += search(len - 1, true, diff + (digit % 2 == 0) * 2 - 1, (r * 10 + digit) % k, num);
      }

      memo[len][same][diff + 10][r] = ret;

      return ret;
    };

    const std::function<int(const std::string&)> helper = [&](const std::string& num) {
      const auto n = static_cast<int>(num.size());

      int result = 0;
      for (int len = 2; len < n; len += 2) {
        for (int d = 1; d <= 9; d++)
          result += search(len - 1, false, (d % 2 == 0) * 2 - 1, d % k, num);
      }

      if (n % 2 == 0) {
        const int digit = num[0] - '0';
        for (int d = 1; d < digit; d++)
          result += search(n - 1, false, (d % 2 == 0) * 2 - 1, d % k, num);
        result += search(n - 1, true, (digit % 2 == 0) * 2 - 1, digit % k, num);
      }

      return result;
    };

    return helper(std::to_string(high)) - helper(std::to_string(low - 1));
  }

public:
  auto numberOfBeautifulIntegers(const int low, const int high, const int k) {
    std::vector table1(11, std::vector(21, std::vector(21, -1)));
    std::vector table2(11, std::vector(21, std::vector(21, -1)));
    std::string s = std::to_string(high);

    const std::function<int(std::vector<std::vector<std::vector<int>>>&, int, int, int, bool, bool)> search = [&
        ](
        std::vector<std::vector<std::vector<int>>>& table,
        const int pos,
        const int mod,
        const int diff,
        const bool lead,
        const bool limit) {
      if (pos >= s.size()) { return mod == 0 and diff == 10 ? 1 : 0; }
      if (not lead and not limit and table[pos][mod][diff] != -1) { return table[pos][mod][diff]; }
      int ans = 0;
      const int up = limit ? s[pos] - '0' : 9;
      for (int i = 0; i <= up; ++i) {
        if (i == 0 and lead) { ans += search(table, pos + 1, mod, diff, true, limit and i == up); } else {
          const int nxt = diff + (i % 2 == 1 ? 1 : -1);
          ans += search(table, pos + 1, (mod * 10 + i) % k, nxt, false, limit and i == up);
        }
      }
      if (not lead and not limit) { table[pos][mod][diff] = ans; }
      return ans;
    };

    const int a = search(table1, 0, 0, 10, true, true);
    s = std::to_string(low - 1);
    const int b = search(table2, 0, 0, 10, true, true);
    return a - b;
  }
};
