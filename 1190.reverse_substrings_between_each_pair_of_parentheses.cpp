#include <algorithm>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  auto reverseParenthesesFast(const std::string& s) {
    std::string result;
    std::vector<int> left;
    for (const auto ch: s) {
      if (ch == '(') { left.push_back(result.size()); } else if (ch == ')') {
        const int j = left.back();
        left.pop_back();
        std::reverse(result.begin() + j, result.end());
      } else { result.push_back(ch); }
    }
    return result;
  }

  auto reverseParentheses(const std::string& s) {
    const int n = s.size();
    std::vector<int> d(n);
    std::stack<int> stk;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') { stk.push(i); } else if (s[i] == ')') {
        const int j = stk.top();
        stk.pop();
        d[i] = j;
        d[j] = i;
      }
    }

    std::string result;
    for (int i = 0, x = 1; i < n; i += x) {
      if (s[i] == '(' or s[i] == ')') {
        i = d[i];
        x = -x;
      } else { result.push_back(s[i]); }
    }
    return result;
  }
};
