#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  string shiftingLetters(string& s, const vector<int>& shifts) {
    int shift = 0;
    for (int i = s.size() - 1; ~i; --i) {
      shift += shifts[i];
      shift %= 26;
      s[i] = ('a' + (s[i] - 'a' + shift) % 26);
    }
    return s;
  }
};
