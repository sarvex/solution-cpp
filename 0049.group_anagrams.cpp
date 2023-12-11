#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;
using std::ranges::sort;

class Solution {
public:
  auto groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> d;
    for (auto &s : strs) {
      string k = s;
      sort(k);
      d[k].emplace_back(s);
    }
    vector<vector<string>> result;
    result.reserve(d.size());
    for (auto &[_, v] : d)
      result.emplace_back(v);
    return result;
  }
};
