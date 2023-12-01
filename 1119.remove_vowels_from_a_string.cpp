class Solution {
public:
    string removeVowels(string s) {
        string ans;
        for (char& c : s) {
            if (!(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')) {
                ans += c;
            }
        }
        return ans;
    }
};