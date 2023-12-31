#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int minMutation(std::string& startGene, const std::string& endGene, const std::vector<std::string>& bank) {
    std::unordered_set<std::string> s;
    for (auto& b: bank) s.insert(b);
    std::unordered_map<char, std::string> mp{ { 'A', "TCG" }, { 'T', "ACG" }, { 'C', "ATG" }, { 'G', "ATC" }, };
    std::queue<std::pair<std::string, int>> q;
    q.emplace( startGene, 0 );
    while (! q.empty()) {
      auto p = q.front();
      q.pop();
      std::string t = p.first;
      const int step = p.second;
      if (t == endGene) return step;
      for (int i = 0; i < t.size(); ++i) {
        for (const auto& c: mp[t[i]]) {
          if (std::string next = t.substr(0, i) + c + t.substr(i + 1, t.size() - i - 1); s.contains(next)) {
            q.emplace( next, step + 1 );
            s.erase(next);
          }
        }
      }
    }
    return -1;
  }
};
