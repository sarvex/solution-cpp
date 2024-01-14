#include <cstdint>
#include <string>
#include <unordered_set>

class Solution {
public:
  int64_t countVowels(const std::string& word) {
    int64_t result = 0;
    static constexpr std::unordered_set vowels{'a', 'e', 'i', 'o', 'u'};
    for (int i = 0, n = word.size(); i < n; ++i) {
      if (vowels.contains(word[i])) result += (i + 1LL) * (n - i);
    }
    return result;
  }
};
