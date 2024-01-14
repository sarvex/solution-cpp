#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <vector>


class Fancy {
  static constexpr int mod = 1e9 + 7;
  std::vector<int64_t> sums_;
  std::vector<int64_t> products_ = { 1, 1 };
  int64_t product_ = 1, inverse_ = 1, sum_ = 0;

public:
  Fancy() {
    const std::function<int64_t(int64_t, int64_t)> power = [&](int64_t b, int64_t p) {
      b %= mod, p %= mod;
      int64_t result = 1;
      while (p) {
        if (p & 1) result = result * b % mod;
        b = b * b % mod, p /= 2;
      }
      return result;
    };

    for (int p = 2; p <= 100; ++p) products_.push_back(power(p, mod - 2));
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
  };

  void append(const int val) { sums_.push_back(((val - sum_) * inverse_) % mod); }

  void addAll(const int inc) { sum_ += inc; }

  void multAll(const int m) {
    product_ = product_ * m % mod;
    inverse_ = inverse_ * products_[m] % mod;
    sum_ = sum_ * m % mod;
  }

  [[nodiscard]] auto getIndex(const int idx) const {
    if (idx >= sums_.size()) { return -1; }
    return ((sums_[idx] * product_ % mod + sum_) % mod + mod) % mod;
  }
};
