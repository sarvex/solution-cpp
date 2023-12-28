#include <string>

using std::string;

class Solution {
public:
  auto numDecodings(string s) {
    const int n = s.size();
    int frequency = 0, result = 1;
    for (int i = 0; i < n; ++i) {
      int index = s[i] != '0' ? result : 0;
      if (i and (s[i - 1] == '1' or (s[i - 1] == '2' and s[i] < '7')))
        index += frequency;
      frequency = result;
      result = index;
    }
    return result;
  }
};
