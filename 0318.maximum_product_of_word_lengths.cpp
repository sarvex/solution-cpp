#include <string>
#include <vector>

class Solution {
public:
  int maxProduct(const std::vector<std::string>& words) {
    int n = words.size();
    std::vector mask(n, 0);
    int result = 0;
    for (int i = 0; i < n; ++i) {
      for (const char& c: words[i]) { mask[i] |= 1 << (c - 'a'); }
      for (int j = 0; j < i; ++j) {
        if ((mask[i] & mask[j]) == 0) { result = std::max(result, static_cast<int>(words[i].size() * words[j].size())); }
      }
    }
    return result;
  }
};
