class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        auto check = [](char c) -> bool {
            return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
        };
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            auto w = words[i];
            ans += check(w[0]) and check(w[w.size() - 1]);
        }
        return ans;
    }
};