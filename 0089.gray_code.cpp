#include <vector>

using std::vector;

class Solution {
public:
  auto grayCode(int n) {
    vector<int> ans;
    for (int i = 0; i < 1 << n; ++i) {
      ans.push_back(i ^ (i >> 1));
    }
    return ans;
  }
};
