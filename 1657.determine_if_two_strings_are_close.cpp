#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  bool closeStrings(const std::string& word1, const std::string& word2) {
    std::vector cnt1(26, 0);
    std::vector cnt2(26, 0);
    for (auto& c: word1) { ++cnt1[c - 'a']; }
    for (auto& c: word2) { ++cnt2[c - 'a']; }
    for (int i = 0; i < 26; ++i) {
      if ((cnt1[i] > 0 and cnt2[i] == 0) or (cnt1[i] == 0 and cnt2[i] > 0)) return false;
    }
    sort(cnt1.rbegin(), cnt1.rend());
    sort(cnt2.rbegin(), cnt2.rend());
    for (int i = 0; i < 26; ++i) if (cnt1[i] != cnt2[i]) return false;
    return true;
  }
};
