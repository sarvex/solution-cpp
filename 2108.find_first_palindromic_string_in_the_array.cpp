#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  Solution() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
  }

  auto firstPalindrome(const std::vector<std::string>& words) -> std::string {
    const auto& result = find_if(cbegin(words), cend(words), [](const auto& word) {
      return equal(cbegin(word), cbegin(word) + size(word) / 2, crbegin(word));
    });
    return result == cend(words) ? "" : *result;
  }
};
