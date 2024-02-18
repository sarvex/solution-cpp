#include <functional>
#include <sstream>
#include <string>
#include <vector>

class Solution {

public:
  auto numberToWords(int num) -> std::string {
    static const std::vector twenty { "",         "One",     "Two",     "Three",     "Four",     "Five",    "Six",
                                      "Seven",    "Eight",   "Nine",    "Ten",       "Eleven",   "Twelve",  "Thirteen",
                                      "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    static const std::vector tens { "",      "Ten",   "Twenty",  "Thirty", "Forty",
                                    "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    static const std::vector thousands { "Billion", "Million", "Thousand", "" };

    const std::function<std::string(int)> transfer = [&](const int number) -> std::string {
      if (number == 0) return "";
      if (number < 20) return std::string(twenty[number]) + " ";
      if (number < 100) return std::string(tens[number / 10]) + " " + transfer(number % 10);
      return std::string(twenty[number / 100]) + " Hundred " + transfer(number % 100);
    };

    if (num == 0) { return "Zero"; }

    std::ostringstream result;
    for (int i = 1000000000, j = 0; i > 0; i /= 1000, ++j) {
      if (num / i == 0) { continue; }
      result << transfer(num / i) << thousands[j] << " ";
      num %= i;
    }
    std::string trim = result.str();
    if (const size_t end = trim.find_last_not_of(' '); end != std::string::npos) trim.resize(end + 1);
    return trim;
  }
};
