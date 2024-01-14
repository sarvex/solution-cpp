#include <string>
#include <unordered_set>

class Solution {
public:
  bool halvesAreAlike(const std::string& s) {
    std::unordered_set vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    int count = 0;
    const int n = s.size() / 2;
    for (int i = 0; i < n; ++i) {
      count += vowels.contains(s[i]);
      count -= vowels.contains(s[i + n]);
    }
    return count == 0;
  }
};
