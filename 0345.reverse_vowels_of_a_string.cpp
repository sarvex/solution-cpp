#include <string>
#include <vector>

class Solution {
public:
  auto reverseVowels(std::string& s) {
    std::vector vowels(128, false);
    for (auto& c: "aeiouAEIOU") { vowels[c] = true; }
    int left = 0, right = s.size() - 1;
    while (left < right) {
      while (left < right and ! vowels[s[left]]) ++left;
      while (left < right and ! vowels[s[right]]) --right;
      if (left < right) std::swap(s[left++], s[right--]);
    }
    return s;
  }
};
