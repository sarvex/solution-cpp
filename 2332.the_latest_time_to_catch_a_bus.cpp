class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int j = 0, c = 0;
        for (int t : buses) {
            c = capacity;
            while (c and j < passengers.size() and passengers[j] <= t) --c, ++j;
        }
        --j;
        int ans = c ? buses[buses.size() - 1] : passengers[j];
        while (~j and ans == passengers[j]) --j, --ans;
        return ans;
    }
};