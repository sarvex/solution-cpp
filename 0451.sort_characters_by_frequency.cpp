#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::string frequencySort(const std::string& s) {
    std::unordered_map<char, int> cnt;
    for (auto& c: s) ++cnt[c];
    std::vector<char> cs;
    for (auto& [c, _]: cnt) cs.push_back(c);
    std::ranges::sort(cs, [&](const char& a, const char& b) { return cnt[a] > cnt[b]; });
    std::ostringstream ans;
    for (char& c: cs) ans << std::string(cnt[c], c);
    return ans.str();
  }
};
