#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  int evalRPN(const std::vector<std::string>& tokens) {
    std::stack<int> stk;
    for (auto& token: tokens) {
      if (token.size() > 1 or isdigit(token[0])) { stk.push(stoi(token)); } else {
        const int y = stk.top();
        stk.pop();
        const int x = stk.top();
        stk.pop();

        switch (token[0]) {
          case '+': stk.push(x + y); break;
          case '-': stk.push(x - y); break;
          case '*': stk.push(x * y); break;
          default: stk.push(x / y);
        }
      }
    }
    return stk.top();
  }
};
