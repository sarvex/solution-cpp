#include <algorithm>
#include <functional>
#include <string>
#include <vector>

class Node {
public:
  std::vector<Node*> children;
  int v = -1;

  Node() : children(26, nullptr) {}
};

class Solution {
  Node* root_ = new Node();
  int idx_ = 0;

  int insert(const std::string& w) {
    auto node = root_;
    for (char c: w) {
      int i = c - 'a';
      if (node->children[i] == nullptr) { node->children[i] = new Node(); }
      node = node->children[i];
    }
    if (node->v < 0) { node->v = idx_++; }
    return node->v;
  }

public:
  long long minimumCost(
      const std::string& source,
      const std::string& target,
      const std::vector<std::string>& original,
      const std::vector<std::string>& changed,
      const std::vector<int>& cost) {

    constexpr long long inf = 1LL << 60;
    const auto m = cost.size();
    std::vector g(m << 1, std::vector(m << 1, inf));
    std::vector<long long> map(source.length(), -1);

    std::function<long long(int)> dfs = [&](const int i) {
      if (i >= source.length()) return 0LL;
      if (map[i] != -1) return map[i];
      long long res = (source[i] == target[i]) ? dfs(i + 1) : inf;
      auto p = root_, q = root_;
      for (int j = i; j < source.length(); ++j) {
        p = p->children[source[j] - 'a'];
        q = q->children[target[j] - 'a'];
        if (p == nullptr || q == nullptr) { break; }
        if (p->v < 0 || q->v < 0) { continue; }
        if (const auto& temp = g[p->v][q->v]; temp < inf) res = std::min(res, temp + dfs(j + 1));
      }
      return map[i] = res;
    };

    for (int i = 0; i < g.size(); ++i) { g[i][i] = 0; }

    for (int i = 0; i < m; ++i) {
      const auto x = insert(original[i]), y = insert(changed[i]);
      g[x][y] = std::min(g[x][y], static_cast<long long>(cost[i]));
    }

    for (int k = 0; k < idx_; ++k) {
      for (int i = 0; i < idx_; ++i) {
        if (g[i][k] >= inf) { continue; }
        for (int j = 0; j < idx_; ++j) { g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]); }
      }
    }

    long long result = dfs(0);
    return result >= inf ? -1 : result;
  }
};
