#include <vector>
#include <algorithm>
#include <functional>

using std::function;
using std::ranges::sort;
using std::vector;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    sort(candidates);
    vector<vector<int>> result;
    vector<int> t;

    function<void(int, int)> dfs = [&](int i, int s) {
      if (s == 0) {
        result.emplace_back(t);
        return;
      }
      if (i >= candidates.size() or s < candidates[i]) {
        return;
      }
      dfs(i + 1, s);
      t.push_back(candidates[i]);
      dfs(i, s - candidates[i]);
      t.pop_back();
    };
    dfs(0, target);
    return result;
  }
};
