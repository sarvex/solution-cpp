#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  auto groupAnagrams(const std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    for (auto& str: strs) {
      std::string index = str;
      std::ranges::sort(index);
      map[index].emplace_back(str);
    }
    std::vector<std::vector<std::string>> result;
    result.reserve(map.size());
    for (auto &[_, v] : map)
      result.emplace_back(std::move(v));
    return result;
  }
};
