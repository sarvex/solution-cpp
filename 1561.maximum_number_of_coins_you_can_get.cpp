#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
public:
  auto maxCoins(vector<int> &piles) {
    sort(piles.begin(), piles.end());
    int ans = 0;
    for (auto i = piles.size() / 3; i < piles.size() ; i += 2)
      ans += piles[i];
    return ans;
  }
};
