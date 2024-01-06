#include <unordered_map>
#include <vector>

class Solution {
public:
  int minOperations(const std::vector<int>& nums) {
    std::unordered_map<int, int> count;
    for (int num: nums) { ++count[num]; }
    int result = 0;
    for (auto& [_, c]: count) {
      if (c < 2) { return -1; }
      result += (c + 2) / 3;
    }
    return result;
  }
};
