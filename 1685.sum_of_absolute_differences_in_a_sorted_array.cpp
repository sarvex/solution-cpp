#include <vector>
#include <numeric>

using std::vector;
using std::reduce;

class Solution {
public:
    static auto getSumAbsoluteDifferences(vector<int>& nums) {
        auto sum = reduce(nums.cbegin(), nums.cend());
        auto n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; ++i) {
          result[i] = sum - nums[i] * (n - 2 * i);
          sum -= 2 * nums[i];
        }

        return result;
    }
};
