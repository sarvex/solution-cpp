#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  bool makeEqual(const std::vector<std::string>& words) {
    std::vector counter(26, 0);
    for (auto& word: words) { for (const auto c: word) { ++counter[c - 'a']; } }
    const int n = words.size();
    return all_of(counter.cbegin(), counter.cend(), [] (const int i) {return i % n == 0;});
  }
};
