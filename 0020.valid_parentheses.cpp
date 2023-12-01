class Solution {
public:
  bool isValid(string s) {
    string stk;
    for (char c: s) {
      if (c == '(' or c == '{' or c == '[')
        stk.push_back(c);
      else if (stk.empty() or !match(stk.back(), c))
        return false;
      else
        stk.pop_back();
    }
    return stk.empty();
  }

  bool match(char l, char r) {
    return (l == '(' and r == ')') or (l == '[' and r == ']') or (l == '{' and r == '}');
  }
};
