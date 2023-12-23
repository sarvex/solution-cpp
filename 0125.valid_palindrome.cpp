#include <string>

class Solution {
public:
  auto isPalindrome(std::pmr::string s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      while (i < j and not isalnum(s[i])) ++i;
      while (i < j and not isalnum(s[j])) --j;
      if (tolower(s[i]) != tolower(s[j])) return false;
    }
    return true;
  }
};
