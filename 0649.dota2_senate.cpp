#include <queue>
#include <string>

class Solution {
public:
  std::string predictPartyVictory(const std::string& senate) {
    const int n = senate.size();
    std::queue<int> radiant;
    std::queue<int> dire;
    for (int i = 0; i < n; ++i) if (senate[i] == 'R') radiant.push(i); else dire.push(i);
    while (not radiant.empty() and not dire.empty()) {
      if (const int r = radiant.front(), d = dire.front(); r < d) radiant.push(r + n);
      else dire.push(d + n);
      radiant.pop();
      dire.pop();
    }
    return radiant.empty() ? "Dire" : "Radiant";
  }
};
