#include <sstream>
#include <stack>
#include <string>

class Solution {
public:
  std::string decodeStringFast(const std::string& s) {
    std::stack<std::pair<int, std::string>> stk;
    int count = 0;
    std::string result;

    for (const char &c : s) {
      if (c >= '0' && c <= '9') {
        count = count*10 + c-'0';
      } else if (c >= 'a' && c <= 'z') {
        result += c;
      } else if (c == '[') {
        stk.emplace(count, std::move(result));
        count = 0;
        result.clear();
      } else {
        auto [prev_count, prev_prefix] = stk.top();
        stk.pop();

        for (int i = 0; i < prev_count; ++i) {
          prev_prefix += result;
        }
        result = std::move(prev_prefix);
      }
    }

    return result;
  }

  std::string decodeString(std::string s) {
    std::stack<int> s1;
    std::stack<std::string> s2;
    std::ostringstream result;
    int num = 0;
    for (const auto& c: s) {
      if (isdigit(c)) {
        num = num * 10 + c - '0';
      } else if (c == '[') {
        s1.push(num);
        s2.push(result.str());
        num = 0;
        result.clear();
      } else if (c == ']') {
        std::ostringstream t;
        const int n = s1.top();
        s1.pop();
        for (int i = 0; i < n; ++i) t << result.str();
        result.clear();
        result << s2.top() << t.str();
        s2.pop_front();
      } else { result << c; }
    }
    return result.str();
  }
}
