#include <string>
#include <unordered_set>

class Solution {
public:
  std::string nearestPalindromic(const std::string& n) {
    const long x = std::stol(n);
    long result = -1;

    for (const auto get = [&]() {
               const long l = n.size();
               std::unordered_set<long> res;
               res.insert(static_cast<long>(pow(10, l - 1)) - 1);
               res.insert(static_cast<long>(pow(10, l)) + 1);
               const long left = stol(n.substr(0, (l + 1) / 2));
               for (long i = left - 1; i <= left + 1; ++i) {
                 std::string prefix = std::to_string(i);
                 std::string t = prefix + std::string(prefix.rbegin() + (l & 1), prefix.rend());
                 res.insert(stol(t));
               }
               res.erase(stol(n));
               return res;
             };
         const long t: get())
      if (result == -1 or abs(t - x) < abs(result - x) or (abs(t - x) == abs(result - x) and t < result)) result = t;
    return std::to_string(result);
  }
};
