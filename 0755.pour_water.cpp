class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        while (volume--) {
            bool find = false;
            for (int d = -1; d < 2 and not find; d += 2) {
                int i = k, j = k;
                while (i + d >= 0 and i + d < heights.size() and heights[i + d] <= heights[i]) {
                    if (heights[i + d] < heights[i]) {
                        j = i + d;
                    }
                    i += d;
                }
                if (j != k) {
                    find = true;
                    ++heights[j];
                }
            }
            if (not find) {
                ++heights[k];
            }
        }
        return heights;
    }
};