#include <cstdint>
#include <vector>

constexpr int64_t mod = 1e9 + 7;

class SegmentTree {
  std::vector<int64_t> lazy_;
  std::vector<int64_t> sum_;
  int n_;

public:
  std::vector<int64_t> square;

  explicit SegmentTree(const int n) :
    n_(n) {
    lazy_.resize(4 * n_, 0);
    sum_.resize(4 * n_, 0);
    square.resize(4 * n_, 0);
  }

  void update(const int l, const int r, const int i) {
    if (l != r) {
      lazy_[i * 2 + 1] += lazy_[i];
      lazy_[i * 2 + 2] += lazy_[i];
    }
    const int64_t gap = r - l + 1;
    const int64_t new_sum = sum_[i] + lazy_[i] * gap;
    const int64_t new_sqr = square[i] + lazy_[i] * sum_[i] * 2 + lazy_[i] * lazy_[i] * gap;

    sum_[i] = new_sum % mod;
    square[i] = new_sqr % mod;
    lazy_[i] = 0;
  }

  void add(const int x, const int y, const int l = 0, int r = -1, const int i = 0) {
    if (r == -1) r += n_;
    update(l, r, i);

    if (r < x or l > y) return;
    if (l >= x and r <= y) {
      lazy_[i] = 1;
      return update(l, r, i);
    }

    const int m = l + (r - l) >> 1;
    add(x, y, l, m, i * 2 + 1);
    add(x, y, m + 1, r, i * 2 + 2);

    sum_[i] = (sum_[i * 2 + 1] + sum_[i * 2 + 2]) % mod;
    square[i] = (square[i * 2 + 1] + square[i * 2 + 2]) % mod;
  }
};

class Solution {
public:
  auto sumCounts(const std::vector<int>& nums) {
    const auto n = nums.size();
    std::vector last_pos(100001, -1);

    SegmentTree tree(n);
    int64_t result = 0;

    for (int j = 0; j < n; j++) {
      const int st = last_pos[nums[j]] + 1, ed = j;
      tree.add(st, ed);

      result = (result + tree.square[0]) % mod;

      last_pos[nums[j]] = j;
    }
    return result;
  }
};
