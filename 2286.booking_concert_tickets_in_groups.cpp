#include <cstdint>
#include <functional>
#include <iosfwd>
#include <iostream>
#include <limits>
#include <vector>

#pragma GCC optimize("Ofast","inline","-ffast-math", "O3")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

class SegmentTree {
  static constexpr auto left_ = 0;
  static constexpr auto right_ = 1;
  static constexpr auto sum_ = 2;
  static constexpr auto max_ = 3;

  std::vector<std::vector<int64_t>> tree_;
  int m_;

  auto pushup(const uint64_t node) {
    tree_[node][sum_] = tree_[node << 1][sum_] + tree_[node << 1 | 1][sum_];
    tree_[node][max_] = std::max(tree_[node << 1][max_], tree_[node << 1 | 1][max_]);
  }

public:
  SegmentTree(const int n, const int m):
    m_{ m } {
    const int size = n << 2;
    tree_.resize(size, { 0, 0, 0, 0 });

    const std::function<void(int, int, int)> build = [&](const int node, const int l, const int r) {
      tree_[node][left_] = l;
      tree_[node][right_] = r;
      if (l == r) {
        tree_[node][sum_] = m_;
        tree_[node][max_] = m_;
        return;
      }
      const int mid = (l + r) >> 1;
      build(node << 1, l, mid);
      build(node << 1 | 1, mid + 1, r);
      pushup(node);
    };

    build(1, 1, n);
  }

  auto modify(const int64_t node, const int64_t x, const int64_t v) -> void {
    if (tree_[node][left_] == x and tree_[node][right_] == x) {
      tree_[node][sum_] = tree_[node][max_] = v;
      return;
    }
    if (const auto mid = (tree_[node][left_] + tree_[node][right_]) >> 1; x <= mid) modify(node << 1, x, v);
    else modify(node << 1 | 1, x, v);
    pushup(node);
  }

  auto querySum(const int64_t node, const int64_t l, const int64_t r) -> int64_t {
    if (tree_[node][left_] >= l and tree_[node][right_] <= r) { return tree_[node][sum_]; }
    const auto mid = (tree_[node][left_] + tree_[node][right_]) >> 1;
    int64_t v = 0;
    if (l <= mid) v += querySum(node << 1, l, r);
    if (r > mid) v += querySum(node << 1 | 1, l, r);
    return v;
  }

  auto queryIdx(const int node, const int l, const int r, const int k) -> int64_t {
    if (tree_[node][max_] < k) return 0;
    if (tree_[node][left_] == tree_[node][right_]) return tree_[node][left_];
    if (tree_[node << 1][max_] >= k) return queryIdx(node << 1, l, r, k);
    if (r > tree_[node][left_] + tree_[node][right_] >> 1) return queryIdx(node << 1 | 1, l, r, k);
    return 0;
  }
};

class BookMyShow {
public:
  BookMyShow(const int n, const int m) :
    m_{ m }, n_{ n } { tree_ = new SegmentTree(n, m); }

  [[nodiscard]] std::vector<int> gather(const int k, const int maxRow) const {
    const auto i = static_cast<int>(tree_->queryIdx(1, 1, maxRow + 1, k));
    if (i == 0) return {};
    const auto s = static_cast<int>(tree_->querySum(1, i, i));
    tree_->modify(1, i, s - k);
    return { i - 1, (m_ - s) };
  }

  [[nodiscard]] bool scatter(int k, const int maxRow) const {
    if (tree_->querySum(1, 1, maxRow + 1) < k) { return false; }
    for (auto j = tree_->queryIdx(1, 1, maxRow + 1, 1); j <= n_; ++j) {
      const auto s = static_cast<int>(tree_->querySum(1, j, j));
      if (s >= k) {
        tree_->modify(1, j, s - k);
        return true;
      }
      k -= s;
      tree_->modify(1, j, 0);
    }
    return true;
  }

private:
  SegmentTree* tree_;
  int m_, n_;
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
