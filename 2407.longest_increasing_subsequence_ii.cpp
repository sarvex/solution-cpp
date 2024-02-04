#include <vector>

class Node {
public:
  int l;
  int r;
  int v;
};

class SegmentTree {
  std::vector<Node*> tr;

public:
  explicit SegmentTree(const int n) {
    tr.resize(4 * n);
    for (auto& i: tr) i = new Node();
    build(1, 1, n);
  }

  void build(const int node, const int l, const int r) {
    tr[node]->l = l;
    tr[node]->r = r;
    if (l == r) return;
    const int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
  }

  void modify(const int u, const int x, const int v) {
    if (tr[u]->l == x and tr[u]->r == x) {
      tr[u]->v = v;
      return;
    }
    if (const int mid = (tr[u]->l + tr[u]->r) >> 1; x <= mid) modify(u << 1, x, v);
    else modify(u << 1 | 1, x, v);
    pushup(u);
  }

  void pushup(int u) { tr[u]->v = std::max(tr[u << 1]->v, tr[u << 1 | 1]->v); }

  int query(const int u, const int l, const int r) {
    if (tr[u]->l >= l and tr[u]->r <= r) return tr[u]->v;
    const int mid = (tr[u]->l + tr[u]->r) >> 1;
    int v = 0;
    if (l <= mid) v = query(u << 1, l, r);
    if (r > mid) v = std::max(v, query(u << 1 | 1, l, r));
    return v;
  }
};

class Solution {
public:
  int lengthOfLIS(const std::vector<int>& nums, const int k) {
    const auto tree = new SegmentTree(*max_element(nums.begin(), nums.end()));
    int result = 1;
    for (const auto& v: nums) {
      int t = tree->query(1, v - k, v - 1) + 1;
      result = std::max(result, t);
      tree->modify(1, v, t);
    }
    return result;
  }
};
