class Solution {
public:
    int n;
    vector<string> ans;
    unordered_map<char, int> cnt;

    vector<string> generatePalindromes(string s) {
        n = s.size();
        for (char c : s) ++cnt[c];
        string mid = "";
        for (auto& [k, v] : cnt) {
            if (v & 1) {
                if (mid != "") {
                    return ans;
                }
                mid += k;
            }
        }
        search(mid);
        return ans;
    }

    void search(string t) {
        if (t.size() == n) {
            ans.push_back(t);
            return;
        }
        for (auto& [k, v] : cnt) {
            if (v > 1) {
                v -= 2;
                search(k + t + k);
                v += 2;
            }
        }
    }
};