#include <vector>

using std::vector;

class Solution {
public:
  auto findSpecialInteger(const vector<int> &array) {
    int n = array.size();
    int m = n >> 2;
    for (int i = 0; i < n - m; i++) {
      if (array[i] == array[i + m])
        return array[i];
    }
    return 0;
  }
};
