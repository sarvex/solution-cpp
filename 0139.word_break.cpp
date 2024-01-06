#include <functional>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) {
    std::vector memo(s.size() + 1, true);

    std::function<bool(int)> search = [&](const int i) {
      if (i >= s.size() or not memo[i]) return false;
      for (auto& word: wordDict)
        if (auto ch = s.substr(i, word.size()); ch == word)
          if (s.size() == i + word.size() or search(i + word.size())) return true;
      memo[i] = false;
      return false;
    };
    return search(0);
  }

  bool wordBreak(const std::string s, const std::vector<std::string>& wordDict) {
    std::unordered_set words(wordDict.begin(), wordDict.end());
    const int n = s.size();
    std::vector result(n + 1, false);
    result[0] = true;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (result[j] and words.contains(s.substr(j, i - j))) {
          result[i] = true;
          break;
        }
      }
    }
    return result[n];
  }
};
