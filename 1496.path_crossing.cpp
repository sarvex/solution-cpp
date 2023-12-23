#include <string>
#include <unordered_set>

class Solution {
public:
  bool isPathCrossing(std::string path) {
    int i = 0, j = 0;
    std::unordered_set s{ { 0 } };
    for (char& c: path) {
      if (c == 'N') { --i; } else if (c == 'S') { ++i; } else if (c == 'E') { ++j; } else { --j; }
      int t = i * 20000 + j;
      if (s.contains(t)) { return true; }
      s.insert(t);
    }
    return false;
  }
};
