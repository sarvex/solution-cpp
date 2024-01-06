#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
  bool arrayStringsAreEqual(const std::vector<std::string>& word1, const std::vector<std::string>& word2) {
    return reduce(word1.cbegin(), word1.cend()) == reduce(word2.cbegin(), word2.cend());
  }
};
