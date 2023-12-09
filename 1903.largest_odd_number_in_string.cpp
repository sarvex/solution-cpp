#include <string>

using std::string;

class Solution {
public:
    string largestOddNumber(string num) {
        size_t pos = 0;
        if (pos = num.find_last_of("13579"); string::npos != pos)
          pos = pos+1;

        return num.substr(0, pos);
    }
};
