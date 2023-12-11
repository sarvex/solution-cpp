#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  auto lengthOfLongestSubstring(const string& s) {
    int start = 0;
    int result = 0;

    vector<int> pos(128, -1);

    for (int i = 0; i < s.size(); i++) {
      if (pos[s[i]] == -1 or pos[s[i]] < start) {
        result = std::max(result, i - start + 1);
      } else {
        start = pos[s[i]] + 1;
      }
      pos[s[i]] = i;
    }

    return result;
  }
};
