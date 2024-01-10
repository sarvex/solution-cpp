#include <string>

class Solution {
public:
  int maxVowels(const std::string& s, const int k) {
    const int n = s.size();
    const auto is_vowel = [] (auto& c) { return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'; }

    int count = 0;
    for (int i = 0; i < k; ++i) count += is_vowel(s[i]);
    int result = count;

    for (int i = k; i < n; ++i) {
      count += is_vowel(s[i]);
      count -= is_vowel(s[i - k]);
      result = std::max(result, count);
    }
    return result;
  }
};
