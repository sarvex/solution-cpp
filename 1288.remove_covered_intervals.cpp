#include <algorithm>
#include <vector>

using std::ranges::sort;
using std::vector;

class Solution {
public:
  auto removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals, [](const vector<int>& a, const vector<int>& b){
      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    auto result = 1;
    auto back = intervals[0];
    for (auto i = 1; i < intervals.size(); ++i) {
      if (back[1] < intervals[i][1]) {
        back = intervals[i];
        ++result;
      }
    }
    return result;
  }
};

