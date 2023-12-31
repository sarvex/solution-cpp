#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<double> calcEquation(
      const std::vector<std::vector<std::string>>& equations,
      const std::vector<double>& values,
      const std::vector<std::vector<std::string>>& queries) {
    const int n = equations.size();

    std::unordered_map<std::string, std::string> p;
    std::unordered_map<std::string, double> w;

    std::function<std::string(const std::string&)> find = [&](const std::string& x) {
      if (p[x] != x) {
        const std::string origin = p[x];
        p[x] = find(p[x]);
        w[x] *= w[origin];
      }
      return p[x];
    };

    for (auto e: equations) {
      p[e[0]] = e[0];
      p[e[1]] = e[1];
      w[e[0]] = 1.0;
      w[e[1]] = 1.0;
    }
    for (int i = 0; i < n; ++i) {
      std::vector<std::string> e = equations[i];
      std::string pa = find(e[0]), pb = find(e[1]);
      if (pa == pb) continue;0
      p[pa] = pb;
      w[pa] = w[e[1]] * values[i] / w[e[0]];
    }
    const int m = queries.size();
    std::vector result(m, -1.0);
    for (int i = 0; i < m; ++i) {
      if (const std::string c = queries[i][0], d = queries[i][1]; p.contains(c) and p.contains(d) and find(c) == find(d))
        result[i] = w[c] / w[d];
    }
    return result;
  }
};
