#include <functional>
#include <vector>

using std::function;
using std::vector;

class Solution {
public:
  auto permute(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> t(n);
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int i) {
      if (i == n) {
        ans.emplace_back(t);
        return;
      }
      for (int j = 0; j < n; ++j) {
        if (not vis[j]) {
          vis[j] = true;
          t[i] = nums[j];
          dfs(i + 1);
          vis[j] = false;
        }
      }
    };
    dfs(0);
    return ans;
  }
};
