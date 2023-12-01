class Solution {
public:
    string toLowerCase(string s) {
        for (char& c : s) {
            if (c >= 'A' and c <= 'Z') {
                c |= 32;
            }
        }
        return s;
    }
};