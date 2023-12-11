#include <deque>
#include <sstream>
#include <string>

using std::deque;
using std::string;
using std::stringstream;

class Solution {
public:
  auto simplifyPath(const string& path) {
    deque<string> stk;
    stringstream ss(path);
    string t;
    while (getline(ss, t, '/')) {
      if (t == "" or t == ".") {
        continue;
      }
      if (t == "..") {
        if (not stk.empty()) {
          stk.pop_back();
        }
      } else {
        stk.push_back(t);
      }
    }
    if (stk.empty()) {
      return "/";
    }
    string ans;
    for (auto &s : stk) {
      ans += "/" + s;
    }
    return ans;
  }
};
