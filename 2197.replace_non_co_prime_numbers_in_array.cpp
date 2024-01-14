#include <numeric>
#include <vector>

class Solution {
public:
  std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {
    std::vector<int> result;
    for (auto& num: nums) {
      while (not result.empty() and std::gcd(result.back(), num) != 1) {
        num = num * result.back() / std::gcd(num, result.back());
        result.pop_back();
      }
      result.push_back(num);
    }
    return result;
  }
};
