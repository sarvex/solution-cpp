#include <algorithm>
#include <execution>
#include <functional>
#include <vector>

using std::execution::par;
using std::vector;
using std::partial_sort;
using std::greater;

class Solution {
public:
    auto maxProduct(vector<int>& nums) {
        partial_sort(par, nums.begin(), nums.begin() + 2, nums.end(), std::greater{});
        return (nums[0] - 1) * (nums[1] - 1);
    }
};
