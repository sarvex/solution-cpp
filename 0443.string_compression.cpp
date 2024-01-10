#include <string>
#include <vector>

class Solution {
public:
  int compress(std::vector<char>& chars) {
    const int n = chars.size();
    int result = 0;
    for (int i = 0, j = i + 1; i < n;) {
      while (j < n and chars[j] == chars[i]) ++j;
      chars[result++] = chars[i];
      if (j - i > 1) { for (const auto& c: std::to_string(j - i)) { chars[result++] = c; } }
      i = j;
    }
    return result;
  }
};
