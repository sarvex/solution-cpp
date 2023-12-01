class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans = {folder[0]};
        for (int i = 1; i < folder.size(); ++i) {
            int m = ans.back().size();
            int n = folder[i].size();
            if (m >= n or !(ans.back() == folder[i].substr(0, m) and folder[i][m] == '/')) {
                ans.emplace_back(folder[i]);
            }
        }
        return ans;
    }
};