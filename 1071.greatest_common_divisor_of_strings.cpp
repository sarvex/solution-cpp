#include <numeric>
#include <string>

class Solution {
public:
  auto gcdOfStrings(const std::string& str1, const std::string& str2) -> std::string {
    if (str1 + str2 != str2 + str1) return "";
    const int n = std::gcd(str1.size(), str2.size());
    return str1.substr(0, n);
  }
};
