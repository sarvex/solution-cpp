#include <vector>

using std::vector;

class Solution {
public:
  auto generate(const int numRows) {
    vector<vector<int>> result{vector<int>{1}};
    for (auto i = 0; i < numRows - 1; ++i) {
      vector<int> row{1};
      for (auto j = 0; j < result[i].size() - 1; ++j) {
        row.emplace_back(result[i][j] + result[i][j + 1]);
      }
      row.emplace_back(1);
      result.emplace_back(row);
    }
    return result;
  }
};
