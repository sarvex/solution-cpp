#include <stack>
#include <string>

class Solution {
public:
  int calculate(const std::string& s) {
    std::stack<std::pair<int, int>> stk;
    const int n = s.size();
    int result = 0, sign = 1;
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) {
        int x = 0;
        while (i < n and isdigit(s[i])) {
          x = x * 10 + (s[i++] - '0');
        }
        result += sign * x;
        --i;
      } else if (s[i] == '+') {
        sign = 1;
      } else if (s[i] == '-') {
        sign = -1;
      } else if (s[i] == '(') {
        stk.push({result, sign});
        result = 0;
        sign = 1;
      } else if (s[i] == ')') {
        result = stk.top().first + (stk.top().second * result);
        stk.pop();
      }
    }
    return result;
  }
};
