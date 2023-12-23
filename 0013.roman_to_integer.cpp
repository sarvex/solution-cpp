#include <string>
#include <unordered_map>

class Solution {
public:
  auto romanToInt(const std::string& s) {
    std::unordered_map<char, int> nums{
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000},
    };

    int result = nums[s.back()];
    for (int i = 0; i < s.size() - 1; ++i) {
      const int sign = nums[s[i]] < nums[s[i + 1]] ? -1 : 1;
      result += sign * nums[s[i]];
    }
    return result;
  }
};
