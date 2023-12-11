#include <algorithm>
#include <functional>
#include <vector>

using std::function;
using std::sort;
using std::vector;

class Solution {
public:
  auto permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
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
        if (vis[j] or (j and nums[j] == nums[j - 1] and !vis[j - 1])) {
          continue;
        }
        t[i] = nums[j];
        vis[j] = true;
        dfs(i + 1);
        vis[j] = false;
      }
    };
    dfs(0);
    return ans;
  }
};
