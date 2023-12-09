#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using std::cin;
using std::ios_base;
using std::max;
using std::vector;
using std::ranges::sort;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() < 2)
      return intervals;

    sort(intervals, [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0];
    });

    vector<vector<int>> result;
    result.emplace_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
      if (result.back()[1] < intervals[i][0]) {
        result.emplace_back(intervals[i]);
      } else {
        result.back()[1] = std::max(result.back()[1], intervals[i][1]);
      }
    }

    return result;
  }

  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  }
};
