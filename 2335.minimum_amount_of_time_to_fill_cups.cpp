#include <algorithm>
#include <vector>

class Solution {
public:
  int fillCups(std::vector<int>& amount) {
    std::sort(amount.begin(), amount.end());
    if (amount[0] + amount[1] <= amount[2]) return amount[2];
    return (amount[0] + amount[1] + amount[2] + 1) / 2;
  }
};
