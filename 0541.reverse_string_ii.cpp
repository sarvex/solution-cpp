#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        for (int i = 0, n = s.size(); i < n; i += (k << 1)) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }
        return s;
    }
};
