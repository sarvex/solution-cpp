#include <functional>
#include <vector>

using std::function;
using std::vector;

class Solution {
public:
  auto combine(const int n, const int k) {
    vector<vector<int>> ans;
    vector<int> t;
    function<void(int)> dfs = [&](int i) {
      if (t.size() == k) {
        ans.emplace_back(t);
        return;
      }
      if (i > n) {
        return;
      }
      t.emplace_back(i);
      dfs(i + 1);
      t.pop_back();
      dfs(i + 1);
    };
    dfs(1);
    return ans;
  }
};
