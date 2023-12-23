#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  auto intToRoman(int num) {
    static const vector<pair<int, string>> symbol{
      { 1000, "M" }, { 900, "CM" }, { 500, "D" }, { 400, "CD" }, { 100, "C" },
      { 90, "XC" }, { 50, "L" }, { 40, "XL" }, { 10, "X" }, { 9, "IX" },
      { 5, "V" }, { 4, "IV" }, { 1, "I" } };

    string result;

    for (const auto& [value, symbol]: symbol) {
      if (num == 0)
        break;
      while (num >= value) {
        num -= value;
        result += symbol;
      }
    }

    return result;
  }
};
