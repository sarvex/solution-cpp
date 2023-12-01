class Solution {
public:
    int countTime(string time) {
        auto f = [](string s, int m) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                bool a = s[0] == '?' or s[0] - '0' == i / 10;
                bool b = s[1] == '?' or s[1] - '0' == i % 10;
                cnt += a and b;
            }
            return cnt;
        };
        return f(time.substr(0, 2), 24) * f(time.substr(3, 2), 60);
    }
};