#include <functional>
#include <string>
#include <utility>
#include <vector>

class Solution {


public:
  auto letterCombinations(const std::string& digits) {
    if (digits.empty()) return {};

    const std::vector<std::string> map{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    std::vector<std::string> result {""};

    for (auto& digit: digits) {
      std::string chars = map[digit - '2'];
      std::vector<std::string> temp;
      for (auto& elem: result) { for (const auto& ch: chars) { temp.push_back(elem + ch); } }
      result = std::move(temp);
    }
    return result;
  }
};
