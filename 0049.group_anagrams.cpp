#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
  static std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> d;
    for (auto &s : strs) {
      std::string k = s;
      std::ranges::sort(k);
      d[k].emplace_back(s);
    }
    std::vector<std::vector<std::string>> result;
    result.reserve(d.size());
    for (auto &[_, v] : d)
      result.emplace_back(v);
    return result;
  }
};
