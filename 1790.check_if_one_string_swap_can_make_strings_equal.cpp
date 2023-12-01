class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        char c1 = 0, c2 = 0;
        for (int i = 0; i < s1.size(); ++i) {
            char a = s1[i], b = s2[i];
            if (a != b) {
                if (++cnt > 2 or (cnt == 2 and (a != c2 or b != c1))) {
                    return false;
                }
                c1 = a, c2 = b;
            }
        }
        return cnt != 1;
    }
};