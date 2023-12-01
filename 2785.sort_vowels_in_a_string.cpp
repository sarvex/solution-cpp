class Solution {
public:
    string sortVowels(string s) {
        string vs;
        for (auto c : s) {
            char d = tolower(c);
            if (d == 'a' or d == 'e' or d == 'i' or d == 'o' or d == 'u') {
                vs.push_back(c);
            }
        }
        sort(vs.begin(), vs.end());
        for (int i = 0, j = 0; i < s.size(); ++i) {
            char d = tolower(s[i]);
            if (d == 'a' or d == 'e' or d == 'i' or d == 'o' or d == 'u') {
                s[i] = vs[j++];
            }
        }
        return s;
    }
};