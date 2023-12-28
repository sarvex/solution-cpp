#include <algorithm>
#include <string>

class Solution {
public:
  int minOperations(const std::string& s) {
    int count = 0;
    const int n = s.size();
    for (int i = 0; i < n; ++i) count += s[i] != "01"[i & 1];
    return std::min(count, n - count);
  }
};
