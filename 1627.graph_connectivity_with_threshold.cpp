#include <numeric>
#include <vector>

using std::vector;
using std::iota;

class UnionFind {
public:
  UnionFind(int n) {
    p_ = vector<int>(n);
    size = vector<int>(n, 1);
    iota(p_.begin(), p_.end(), 0);
  }

  bool unite(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa == pb) { return false; }
    if (size[pa] > size[pb]) {
      p_[pb] = pa;
      size[pa] += size[pb];
    } else {
      p_[pa] = pb;
      size[pb] += size[pa];
    }
    return true;
  }

  int find(int x) {
    if (p_[x] != x) { p_[x] = find(p_[x]); }
    return p_[x];
  }

private:
  vector<int> p_, size;
};

class Solution {
public:
  vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
    UnionFind uf(n + 1);
    for (int a = threshold + 1; a <= n; ++a) { for (int b = a + a; b <= n; b += a) { uf.unite(a, b); } }
    vector<bool> ans;
    for (auto& q: queries) { ans.push_back(uf.find(q[0]) == uf.find(q[1])); }
    return ans;
  }
};
