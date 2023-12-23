#include <vector>

class Solution {
public:
  int canCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost) {

    int current = 0, total = 0, diff = 0, start = 0

    for (int i = 0; i < gas.size(); i++) {
      diff = gas[i] - cost[i];

      total += diff;
      current += diff;
      if (current < 0) {
        start = i + 1;
        current = 0;
      }
    }

    return total >= 0 ? start : -1;
  }
};
