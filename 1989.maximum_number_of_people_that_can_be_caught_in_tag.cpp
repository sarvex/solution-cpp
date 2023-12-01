class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        int ans = 0;
        int n = team.size();
        for (int i = 0, j = 0; i < n; ++i) {
            if (team[i]) {
                while (j < n and (team[j] or i - j > dist)) {
                    ++j;
                }
                if (j < n and abs(i - j) <= dist) {
                    ++ans;
                    ++j;
                }
            }
        }
        return ans;
    }
};