#include <stack>
#include <string>

class Solution {
public:
  auto isValidFast(const std::string& s) {
    std::stack<char> brackets;

    for (char c: s) {
      if (c == '(' or c == '[' or c == '{') brackets.push(c);
      else {
        if (brackets.empty() or (c == ')' and brackets.top() != '(') or (c == '}' and brackets.top() != '{')
            or (c == ']' and brackets.top() != '['))
          return false;
        brackets.pop();
      }
    }

    return brackets.empty();
  }

  auto isValid(const std::string& s) {
    std::string stk;

    const auto match = [](const auto& l, const auto& r) {
      return (l == '(' and r == ')') or (l == '[' and r == ']') or (l == '{' and r == '}');
    };

    for (char c: s) {
      if (c == '(' or c == '{' or c == '[') stk.push_back(c);
      else if (stk.empty() or not match(stk.back(), c)) return false;
      else stk.pop_back();
    }
    return stk.empty();
  }
};
