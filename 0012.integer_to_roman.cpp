#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  auto intToRoman(int num) {
    const vector<string> roman = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                  "XL", "X",  "IX", "V",  "IV", "I"};
    const vector integer = {1000, 900, 500, 400, 100, 90, 50,
                            40,   10,  9,   5,   4,   1};

    string result;

    for (int i = 0; i < roman.size(); ++i) {
      while (num >= integer[i]) {
        num -= integer[i];
        result += roman[i];
      }
    }
    return result;
  }
};
