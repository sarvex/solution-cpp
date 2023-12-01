#include <algorithm>
#include <iostream>
#include <string>

using std::reverse;
using std::string;

class Solution {
public:
  static string reverseWords(string s) {

    for (int i = 0; i < s.size();) {
      auto j = s.find_first_of(' ', i);
      if (j == string::npos) {
        reverse(s.begin() + i, s.end());
        break;
      } else {
        reverse(s.begin() + i, s.begin() + j);
        i = j + 1;
      }
    }
    return s;
  }
};

auto main() -> int {
  string s1 = "Let's take LeetCode contest";
  string s2 = "God Ding";

  std::cout << Solution::reverseWords(s1) << std::endl;
  std::cout << Solution::reverseWords(s2) << std::endl;

  return 0;
}
