#include <string>

using std::string;

class Solution {
public:
  auto isValid(const string& s) {
    string stk;

    const auto match = [] (auto& l, auto& r) {
      return (l == '(' and r == ')') or (l == '[' and r == ']') or (l == '{' and r == '}');
    };

    for (char c: s) {
      if (c == '(' or c == '{' or c == '[')
        stk.push_back(c);
      else if (stk.empty() or not match(stk.back(), c))
        return false;
      else
        stk.pop_back();
    }
    return stk.empty();
  }
};
