#include <algorithm>
#include <vector>

class BinaryIndexedTree {
  int size_;
  std::vector<int> children_;

public:
  explicit BinaryIndexedTree(const int n) :
    size_(n)
    , children_(n + 1) {}

  void update(int x, const int v) {
    while (x <= size_) {
      children_[x] = std::max(children_[x], v);
      x += x & -x;
    }
  }

  int query(int x) {
    int mx = 0;
    while (x) {
      mx = std::max(mx, children_[x]);
      x -= x & -x;
    }
    return mx;
  }
};

class Solution {
public:
  auto lengthOfLISFast(const std::vector<int>& nums) {
    const int n = nums.size();
    std::vector result{ nums[0] };
    for (int i = 1; i < n; i++) {
      if (result.back() < nums[i]) { result.push_back(nums[i]); } else {
        const int index = lower_bound(result.begin(), result.end(), nums[i]) - result.begin();
        result[index] = nums[i];
      }
    }
    return result.size();
  }

  int lengthOfLIS(const std::vector<int>& nums) {
    std::vector<int> s = nums;
    std::ranges::sort(s);
    s.erase(unique(s.begin(), s.end()), s.end());
    BinaryIndexedTree tree(s.size());
    for (int x: nums) {
      x = lower_bound(s.begin(), s.end(), x) - s.begin() + 1;
      const int t = tree.query(x - 1) + 1;
      tree.update(x, t);
    }
    return tree.query(s.size());
  }
};
