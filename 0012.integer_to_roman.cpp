#include <string>
#include <vector>

class Solution {
public:
  static std::string intToRoman(int num) {
    const std::vector<std::string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const std::vector integer = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    std::string result;

    for (int i = 0; i < roman.size(); ++i) {
      while (num >= integer[i]) {
        num -= integer[i];
        result += roman[i];
      }
    }
    return result;
  }
};
