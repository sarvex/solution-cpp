#include <string>
#include <vector>

using std::string;
using std::vector;
using std::to_string;

class Solution {
public:
  vector<string> generateAbbreviations(const string& word) const {
    int n = word.size();
    vector<string> result;
    for (int i = 0; i < 1 << n; ++i) {
      string s;
      int count = 0;
      for (int j = 0; j < n; ++j) {
        if (i >> j & 1) { ++count; } else {
          if (count) {
            s += to_string(count);
            count = 0;
          }
          s.push_back(word[j]);
        }
      }
      if (count) { s += to_string(count); }
      result.push_back(s);
    }
    return result;
  }
};
