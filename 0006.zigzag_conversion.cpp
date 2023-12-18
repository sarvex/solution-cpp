#include <string>

using std::string;

class Solution {
public:
  auto convert(const string& s, const int num_rows) {
    if (num_rows == 1) return s;
    string result;
    const int group = 2 * num_rows - 2;
    for (auto i = 1; i <= num_rows; ++i) {
      int interval = i == num_rows ? group : 2 * num_rows - 2 * i;
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
