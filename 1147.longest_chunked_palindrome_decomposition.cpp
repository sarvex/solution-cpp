#include <string>

class Solution {
public:
  int longestDecomposition(const std::string& text) {
    int result = 0;
    auto check = [&](int i, int j, int k) {
      while (k--) if (text[i++] != text[j++]) return false;
      return true;
    };
    for (int i = 0, j = text.size() - 1; i <= j;) {
      bool ok = false;
      for (int k = 1; i + k - 1 < j - k + 1; ++k) {
        if (check(i, j - k + 1, k)) {
          result += 2;
          i += k;
          j -= k;
          ok = true;
          break;
        }
      }
      if (! ok) {
        ++result;
        break;
      }
    }
    return result;
  }
};
