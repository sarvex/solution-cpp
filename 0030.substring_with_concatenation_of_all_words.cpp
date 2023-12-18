#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
  auto findSubstring(const string& s, const vector<string>& words) {
    unordered_map<string, int> cnt;
    for (auto& w: words) {
      ++cnt[w];
    }
    const auto m = s.size();
    const auto n = words.size();
    const auto k = words[0].size();
    vector<int> ans;
    for (auto i = 0; i < k; ++i) {
      unordered_map<string, int> cnt1;
      int l = i, r = i;
      auto t = 0;
      while (r + k <= m) {
        string w = s.substr(r, k);
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
          string remove = s.substr(l, k);
          l += k;
          --cnt1[remove];
          --t;
        }
        if (t == n) {
          ans.push_back(l);
        }
      }
    }
    return result;
  }
};
