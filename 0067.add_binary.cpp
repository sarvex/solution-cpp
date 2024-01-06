#include <algorithm>
#include <string>

class Solution {
public:
  auto addBinary(const std::string& a, const std::string& b) {
    std::string result;
    int i = a.size() - 1, j = b.size() - 1;
    for (int carry = 0; i >= 0 or j >= 0 or carry; --i, --j) {
      carry += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
      result.push_back((carry % 2) + '0');
      carry /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
