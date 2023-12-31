#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  auto maxLengthBetweenEqualCharactersFast(const std::string& s) {
    std::unordered_map<char, int> map;
    int result = 0;

    for (auto index = 0; index < s.length(); ++index) {
      char c = s[index];

      if (auto it = map.find(c); it != map.end()) {
        if (const int diff = index - it->second; result < diff)
          result = diff;
        continue;
      }
      map[c] = index;
    }
    return result - 1;
  }

  auto maxLengthBetweenEqualCharacters(const std::string& s) {
    std::vector d(26, -1);
    int result = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (const int j = s[i] - 'a'; d[j] == -1) { d[j] = i; } else { result = std::max(result, i - d[j] - 1); }
    }
    return result;
  }
};
