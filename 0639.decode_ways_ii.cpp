#include <cstdint>
#include <string>

class Solution {

public:
  int numDecodingsFast(const std::string& s) {
    if (s.empty() || s[0] == '0') return 0;

    const int MOD = 1e9 + 7;
    const auto n = s.length();

    int64_t prev = 1, result = s[0] == '*' ? 9 : s[0] != '0' ? 1 : 0;

    for (int i = 1; i < n; i++) {
      int64_t temp = 0;

      if (s[i] == '*') {
        temp = (9 * result) % MOD; // '*' can be replaced with any of the digits from 1 to 9
        if (s[i - 1] == '1')
          temp = (temp + 9 * prev) % MOD; // "1*" can represent any number from 10 to 19
        else if (s[i - 1] == '2')
          temp = (temp + 6 * prev) % MOD; // "2*" can represent any number from 20 to 26
        else if (s[i - 1] == '*')
          temp = (temp + 15 * prev) % MOD; // "**" can represent any valid number from 10 to 26
      } else {
        temp = (s[i] != '0' ? result : 0); // single digit decode
        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
          temp = (temp + prev) % MOD; // valid two-digit decode
        else if (s[i - 1] == '*') {
          if (s[i] <= '6')
            temp = (temp + 2 * prev) % MOD; // "*" followed by a digit <= 6 can be '1' or '2'
          else
            temp = (temp + prev) % MOD; // "*" followed by a digit > 6 can only be '1'
        }
      }
      prev = result;
      result = temp;
    }

    return static_cast<int>(result);
  }

  int numDecodings(const std::string& s) {
    static const int MOD = 1000000007;
    const auto n = s.size();

    int64_t a = 0, b = 1, c = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '*') { c = 9 * b % MOD; } else if (s[i - 1] != '0') { c = b; } else { c = 0; }

      if (i > 1) {
        if (s[i - 2] == '*' and s[i - 1] == '*') { c = (c + 15 * a) % MOD; } else if (s[i - 2] == '*') {
          if (s[i - 1] > '6') { c = (c + a) % MOD; } else { c = (c + 2 * a) % MOD; }
        } else if (s[i - 1] == '*') {
          if (s[i - 2] == '1') { c = (c + 9 * a) % MOD; } else if (s[i - 2] == '2') { c = (c + 6 * a) % MOD; }
        } else if (s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26) { c = (c + a) % MOD; }
      }

      a = b;
      b = c;
    }

    return static_cast<int>(c);
  }
};
