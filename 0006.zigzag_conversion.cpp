#include <string>

using std::string;

class Solution {
public:
  auto convert(const string& s, const int numRows) {
    if (numRows == 1) return s;
    string result;
    const int group = 2 * numRows - 2;
    for (auto i = 1; i <= numRows; ++i) {
      int interval = i == numRows ? group : 2 * numRows - 2 * i;
      int idx = i - 1;
      while (idx < s.size()) {
        result.push_back(s[idx]);
        idx += interval;
        interval = group - interval;
        if (interval == 0) interval = group;
      }
    }
    return result;
  }
};
