#include <algorithm>
#include <vector>

class BinaryIndexedTree {
  int size_;
  std::vector<long long> c_;
  constexpr long long inf_ = 1e18;

public:
  explicit BinaryIndexedTree(int n) {
    this->size_ = n;
    c_.resize(n + 1, -inf_);
  }

  void update(int x, const long long v) {
    while (x <= size_) {
      c_[x] = std::max(c_[x], v);
      x += x & -x;
    }
  }

  long long query(int x) {
    long long mx = -inf_;
    while (x > 0) {
      mx = std::max(mx, c_[x]);
      x -= x & -x;
    }
    return mx;
  }
};

class Solution {
public:
  long long maxBalancedSubsequenceSum(const std::vector<int>& nums) {
    const auto n = nums.size();
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) { arr[i] = nums[i] - i; }
    std::ranges::sort(arr);
    arr.erase(std::ranges::unique(arr).begin(), arr.end());
    const int m = static_cast<int>(arr.size());
    BinaryIndexedTree tree(m);
    for (int i = 0; i < n; ++i) {
      int j = std::ranges::lower_bound(arr, nums[i] - i) - arr.begin() + 1;
      const long long v = std::max(tree.query(j), 0LL) + nums[i];
      tree.update(j, v);
    }
    return tree.query(m);
  }
};
