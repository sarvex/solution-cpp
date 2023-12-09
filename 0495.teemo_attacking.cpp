#include <vector>
#include <ios>
#include <iostream>
#include <algorithm>

using std::vector;
using std::ios_base;
using std::cin;
using std::min;

class Solution {
public:
    int findPoisonedDuration(const vector<int>& timeSeries, const int& duration) {
        int result = duration;
        for (int i = 1; i < timeSeries.size(); ++i) {
          result += min(duration, timeSeries[i] - timeSeries[i-1]);
        }
        return result;
    }

    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};
