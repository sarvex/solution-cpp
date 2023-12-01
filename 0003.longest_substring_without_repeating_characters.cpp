#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class Solution {
public:
  static int lengthOfLongestSubstring(string s) {
    auto result = 0;
    unordered_set<char> substring;

    for (int i = 0, j = 0; j < s.size(); ++j) {
      while (substring.contains(s[j]))
        substring.erase(s[i++]);
      substring.insert(s[j]);
      result = std::max(result, j - i + 1);
    }

    return result;
  }
};
