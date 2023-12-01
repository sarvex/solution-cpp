#include <iostream>
#include <string>

class Solution {
public:
  static auto lengthOfLastWord(std::string& s) -> int {
    s.erase(s.find_last_not_of(' ')+1);
    if (s.empty()) return 0;
    auto i = s.rfind(' ');
    return s.size() - i - 1;
  }
};

auto main() -> int {
  std::string s {"Hello, world"};
  std::cout << Solution::lengthOfLastWord(s) << std::endl;

  return 0;
}
