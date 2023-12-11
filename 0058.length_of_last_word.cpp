#include <string>

using std::string;

class Solution {
public:
  auto lengthOfLastWord(string& s) -> int{
    s.erase(s.find_last_not_of(' ') + 1);
    if (s.empty()) return 0;
    return s.size() - s.rfind(' ') - 1;
  }
};

