#include <string>

using std::string;

class Solution {
public:
  string robotWithString(const string& s) {
    int count[26] = { 0 };
    for (auto& c: s) ++count[c - 'a'];
    char index = 'a';
    string robot;
    string result;
    for (auto& c: s) {
      --count[c - 'a'];
      while (index < 'z' and count[index - 'a'] == 0) ++index;
      robot += c;
      while (not robot.empty() and robot.back() <= index) {
        result += robot.back();
        robot.pop_back();
      }
    }
    return result;
  }
};
