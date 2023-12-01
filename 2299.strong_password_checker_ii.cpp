class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) {
            return false;
        }
        int mask = 0;
        for (int i = 0; i < password.size(); ++i) {
            char c = password[i];
            if (i and c == password[i - 1]) {
                return false;
            }
            if (c >= 'a' and c <= 'z') {
                mask |= 1;
            } else if (c >= 'A' and c <= 'Z') {
                mask |= 2;
            } else if (c >= '0' and c <= '9') {
                mask |= 4;
            } else {
                mask |= 8;
            }
        }
        return mask == 15;
    }
};