#include <string>
#include <utility>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
  auto letterCombinations(const string& digits) {
    vector<string> result = {""};
    if (digits.empty()) return result;

    vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    for (auto i: digits) {
      string s = map[i - '2'];
      vector<string> t;
      for (auto& a: result) {
        for (auto& b: s) {
          t.push_back(a + b);
        }
      }
      result = std::move(t);
    }
    return result;
  }
};
