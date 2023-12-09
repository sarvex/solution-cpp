#include <iostream>
#include <string>

using std::string;

class Solution {
public:
  static auto lengthOfLastWord(string& s) -> int{
    s.erase(s.find_last_not_of(' ') + 1);
    if (s.empty()) return 0;
    return s.size() - s.rfind(' ') - 1;
  }
};

auto main() -> int {
  string s{ "Hello, world" };
  std::cout << Solution::lengthOfLastWord(s) << std::endl;

  return 0;
}
