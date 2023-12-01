class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> d;
        for (int i = 0; i < nums.size(); ++i) {
            if (d.count(nums[i]) and i - d[nums[i]] <= k) {
                return true;
            }
            d[nums[i]] = i;
        }
        return false;
    }
};