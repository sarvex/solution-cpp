#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  std::string largestNumber(const std::vector<int>& nums) {
    std::vector<std::string> vs;
    for (auto& v : nums) vs.push_back(std::to_string(v));
    std::sort(vs.begin(), vs.end(), [](const std::string& a, const std::string& b) { return a + b > b + a; });
    if (vs[0] == "0") return "0";
    std::string result;
    for (std::string v : vs)
      result += v;
    return result;
  }
};
