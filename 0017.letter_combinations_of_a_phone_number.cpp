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

    const vector<string> map {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    for (const auto& i: digits) {
      string s = map[i - '2'];
      vector<string> t;
      for (const auto& a: result) {
        for (const auto& b: s) {
          t.push_back(a + b);
        }
      }
      result = std::move(t);
    }
    return result;
  }
};
