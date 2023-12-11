#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

using std::vector;
using std::pair;
using std::max;
using std::gcd;
using std::move;

class Solution {
public:
  auto maxGcdSum(vector<int> &nums, int k) {
    int n = nums.size();
    long long s[n + 1];
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
      s[i] = s[i - 1] + nums[i - 1];
    }
    vector<pair<int, int>> f;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      vector<pair<int, int>> g;
      for (auto [j, x] : f) {
        int y = gcd(x, nums[i]);
        if (g.empty() or g.back().second != y) {
          g.emplace_back(j, y);
        }
      }
      f = move(g);
      f.emplace_back(i, nums[i]);
      for (auto [j, x] : f) {
        if (i - j + 1 >= k) {
          ans = max(ans, (s[i + 1] - s[j]) * x);
        }
      }
    }
    return ans;
  }
};
