#include <vector>

using std::vector;

class Solution {
public:
    auto getRow(const int rowIndex) {
      vector<int> result (rowIndex + 1, 1);
        for (auto i = 1; i <= rowIndex; ++i) {
          result[i] = static_cast<uint64_t>(result[i - 1]) * (rowIndex - i + 1) / i;
        }
      return result;
    }
};
