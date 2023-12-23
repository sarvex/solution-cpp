#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  auto longestPalindromeFast(const std::string &s) {
    std::string str{"^#"};
    for (const char c : s)
      str.append({c, '#'});
    str.append("$");

    const auto n = str.size();
    std::vector palindrome(n, 0);
    int center = 0, radius = 0;

    for (int i = 1; i < n - 1; ++i) {
      palindrome[i] =
          (radius > i) ? std::min(radius - i, palindrome[2 * center - i]) : 0;
      while (str[i + 1 + palindrome[i]] == str[i - 1 - palindrome[i]])
        palindrome[i]++;

      if (i + palindrome[i] > radius) {
        center = i;
        radius = i + palindrome[i];
      }
    }

    const auto max_length = *std::max_element(palindrome);
    const auto center_index =
        distance(palindrome.begin(), find(palindrome, max_length));
    return s.substr((center_index - max_length) / 2, max_length);
  }

  auto longestPalindrome(const std::string &s) {
    const int n = s.size();

    std::vector f(n, vector(n, true));
    int k = 0, mx = 1;
    for (int i = n - 2; ~i; --i) {
      for (int j = i + 1; j < n; ++j) {
        f[i][j] = false;
        if (s[i] == s[j]) {
          f[i][j] = f[i + 1][j - 1];
          if (f[i][j] and mx < j - i + 1) {
            mx = j - i + 1;
            k = i;
          }
        }
      }
    }
    return s.substr(k, mx);
  }
};
