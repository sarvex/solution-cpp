#include <string>
#include <vector>

class Solution {
public:
  static std::vector<std::string> letterCombinations(const std::string& digits) {
    if (digits.empty()) return {};
    std::vector<std::string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> result = {""};
    for (auto i: digits) {
      std::string s = map[i - '2'];
      std::vector<std::string> t;
      for (auto& a: result) {
        for (auto& b: s) {
          t.push_back(a + b);
        }
      }
      result = move(t);
    }
    return result;
  }
};
