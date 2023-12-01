class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
        for (int i = 0; i < m; ++i) {
            int n = words[i].size();
            for (int j = 0; j < n; ++j) {
                if (j >= m or i >= words[j].size() or words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};