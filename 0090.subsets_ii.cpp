#include <algorithm>
#include <functional>
#include <vector>

using std::function;
using std::sort;
using std::vector;

class Solution {
public:
  auto subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> t;

    function<void(int, vector<int> &, vector<int> &, vector<vector<int>> &)>
        dfs = [&](int u, vector<int> &t, vector<int> &nums,
                  vector<vector<int>> &ans) {
          ans.push_back(t);
          for (int i = u; i < nums.size(); ++i) {
            if (i != u and nums[i] == nums[i - 1])
              continue;
            t.push_back(nums[i]);
            dfs(i + 1, t, nums, ans);
            t.pop_back();
          }
        };

    dfs(0, t, nums, ans);
    return ans;
  }
};
