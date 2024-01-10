#include <sstream>
#include <string>

class Solution {
public:
  auto mergeAlternately(const std::string& word1, const std::string& word2) {
    const int m = word1.size(), n = word2.size(), size = m < n ? m : n;
    std::ostringstream result;
    for (int i = 0; i < size; ++i) {
      result << word1[i] << word2[i];
    }
    if (m > size) result << word1.substr(size);
    else result << word2.substr(size);
    return result.str();
  }
};
