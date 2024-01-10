#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool uniqueOccurrences(const std::vector<int>& arr) {
    std::unordered_map<int, int> count;
    for (auto& x: arr) { ++count[x]; }
    std::unordered_set<int> seen;
    for (auto& [_, elem]: count) {
      if (seen.contains(elem)) { return false; }
      seen.insert(elem);
    }
    return true;
  }
};
