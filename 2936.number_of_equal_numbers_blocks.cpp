#include <vector>

using std::vector;

class BigArray {
public:
  explicit BigArray(vector<int> elements);
  auto at(long long index) -> int;
  auto size() -> long long;
};

class Solution {
public:
  auto countBlocks(BigArray *nums) {
    int ans = 0;
    using ll = long long;
    ll n = nums->size();
    auto search = [&](ll l) {
      ll r = n;
      int x = nums->at(l);
      while (l < r) {
        ll mid = (l + r) >> 1;
        if (nums->at(mid) != x) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      return l;
    };
    for (long long i = 0; i < n; ++ans) {
      i = search(i);
    }
    return ans;
  }
};
