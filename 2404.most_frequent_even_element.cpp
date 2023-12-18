#include <unordered_map>
#include <algorithm>
#include <vector>

using std::vector;
using std::unordered_map;
using std::ranges::sort;

class Solution {
public:
  int mostFrequentEvenFast(vector<int>& nums) {
    sort(nums);
    int result = -1, count = 0;
    int number = -1, times = 0;
    for (const auto& num: nums) {
      if (num & 1) continue;
      if (num != number) {
        if (times > count) {
          result = number;
          count = times;
        }
        number = num;
        times = 0;
      }
      times++;
    }

    if (times > count) { result = number; }

    return result;
  }

  auto mostFrequentEven(const vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (int x: nums) { if (x % 2 == 0) { ++cnt[x]; } }
    int ans = -1, mx = 0;
    for (auto& [x, v]: cnt) {
      if (mx < v or (mx == v and ans > x)) {
        ans = x;
        mx = v;
      }
    }
    return ans;
  }
};
