class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int m = targetSeconds / 60, s = targetSeconds % 60;
        return min(f(m, s, startAt, moveCost, pushCost), f(m - 1, s + 60, startAt, moveCost, pushCost));
    }

    int f(int m, int s, int prev, int moveCost, int pushCost) {
        if (m < 0 or m > 99 or s < 0 or s > 99) return INT_MAX;
        vector<int> arr = {m / 10, m % 10, s / 10, s % 10};
        int i = 0;
        for (; i < 4 and arr[i] == 0; ++i)
            ;
        int t = 0;
        for (; i < 4; ++i) {
            if (arr[i] != prev) t += moveCost;
            t += pushCost;
            prev = arr[i];
        }
        return t;
    }
};