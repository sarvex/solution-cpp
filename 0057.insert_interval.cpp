#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    auto insert(const vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int n = intervals.size();
        int i = 0;

        vector<vector<int>> result;
        while(i < n and intervals[i][1] < newInterval[0]){
            result.emplace_back(intervals[i++]);
        }

        while(i < n and newInterval[1] >= intervals[i][0]){
            newInterval[0] = std::min(newInterval[0], intervals[i][0]) ;
            newInterval[1] = std::max(newInterval[1], intervals[i][1]) ;
            i++;
        }

        result.emplace_back(newInterval) ;

        while(i < n){
            result.emplace_back(intervals[i++]) ;
        }
        return result ;
    }
};
