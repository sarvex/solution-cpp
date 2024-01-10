class Solution {
  public:
 std::string decodeString(const std::string& s) {
    std::deque<int> s1;
    std::deque<> s2 = new ArrayDeque<>();
    int num = 0;
    String res = "";
    for (char c : s.toCharArray()) {
      if ('0' <= c && c <= '9') {
        num = num * 10 + c - '0';
      } else if (c == '[') {
        s1.push(num);
        s2.push(res);
        num = 0;
        res = "";
      } else if (c == ']') {
        StringBuilder t = new StringBuilder();
        for (int i = 0, n = s1.pop(); i < n; ++i) {
          t.append(res);
        }
        res = s2.pop() + t.toString();
      } else {
        res += String.valueOf(c);
      }
    }
    return res;
  }
}