#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  auto findSubstring(const std::string& s, const std::vector<std::string>& words) {
    std::unordered_map<std::string, int> count;
    for (auto& word: words) { ++count[word]; }
    const auto k = s.size(), m = words.size(), n = words[0].size();
    std::vector<int> result;
    for (auto i = 0; i < n; ++i) {
      std::unordered_map<std::string, int> cnt;
      auto left = i, right = i, mid = 0;
      while (right + n <= k) {
        std::string word = s.substr(right, n);
        right += n;
        if (not count.contains(word)) {
          cnt.clear();
          left = right;
          mid = 0;
          continue;
        }
        ++cnt[word];
        ++mid;
        while (cnt[word] > count[word]) {
          std::string remove = s.substr(left, n);
          left += n;
          --cnt[remove];
          --mid;
        }
        if (mid == m) { result.push_back(left); }
      }
    }
    return result;
  }
};
