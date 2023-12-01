#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<int> findSubstring(const std::string& s, const std::vector<std::string>& words) {
    std::unordered_map<std::string, int> cnt;
    for (auto& w: words) {
      ++cnt[w];
    }
    const auto m = s.size();
    const auto n = words.size();
    const auto k = words[0].size();
    std::vector<int> ans;
    for (auto i = 0; i < k; ++i) {
      std::unordered_map<std::string, int> cnt1;
      int l = i, r = i;
      auto t = 0;
      while (r + k <= m) {
        std::string w = s.substr(r, k);
        r += k;
        if (not cnt.contains(w)) {
          cnt1.clear();
          l = r;
          t = 0;
          continue;
        }
        ++cnt1[w];
        ++t;
        while (cnt1[w] > cnt[w]) {
          std::string remove = s.substr(l, k);
          l += k;
          --cnt1[remove];
          --t;
        }
        if (t == n) {
          ans.push_back(l);
        }
      }
    }
    return ans;
  }
};
