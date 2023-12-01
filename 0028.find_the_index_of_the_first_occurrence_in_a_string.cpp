#include <string>
#include <vector>

class Solution {
  static std::vector<int> next(std::string str) {
    std::vector<int> n(str.length());
    n[0] = -1;
    int i = 0, pre = -1;
    int len = str.length();
    while (i < len) {
      while (pre >= 0 and str[i] != str[pre])
        pre = n[pre];
      ++i, ++pre;
      if (i >= len)
        break;
      if (str[i] == str[pre])
        n[i] = n[pre];
      else
        n[i] = pre;
    }
    return n;
  }

public:
  static int strStr(const std::string& haystack, const std::string& needle) {
    if (needle.empty())
      return 0;

    const std::vector n(next(needle));

    const int len = haystack.length() - needle.length() + 1;
    for (auto i = 0; i < len; ++i) {
      int j = 0, k = i;
      while (j < needle.length() and k < haystack.length()) {
        if (haystack[k] != needle[j]) {
          if (n[j] >= 0) {
            j = n[j];
            continue;
          } else
            break;
        }
        ++k, ++j;
      }
      if (j >= needle.length())
        return k - j;
    }

    return -1;
  }
};
