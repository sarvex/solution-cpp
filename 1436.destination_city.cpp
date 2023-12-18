#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

class Solution {
public:
  auto destCity(const vector<vector<string>>& paths) {
    unordered_set<string> s;
    for (auto& path: paths) { s.emplace(path[0]); }
    for (auto& path: paths) { if (not s.contains(path[1])) { return path[1]; } }
    return "";
  }
};
