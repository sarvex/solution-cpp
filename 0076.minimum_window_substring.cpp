#include <limits>
#include <string>
#include <vector>

class Solution {
public:
  auto minWindowFast(const std::string& s, const std::string& t) {
    std::vector map(128, 0);
    for (auto& c: t) map[c]++;

    int counter = t.size(), begin = 0, end = 0, distance = std::numeric_limits<int>::max(), head = 0;
    const auto n = s.size();;
    while (end < n) {
      if (map[s[end++]]-- > 0) { counter--; }
      while (counter == 0) {
        if (end - begin < distance) {
          head = begin;
          distance = end - head;
        }
        if (map[s[begin++]]++ == 0) counter++;
      }
    }
    return distance == std::numeric_limits<int>::max() ? "" : s.substr(head, distance);
  }

  auto minWindow(const std::string& s, const std::string& t) {
    const auto n = s.size(), m = t.size();

    std::vector need(128, 0);
    std::vector window(128, 0);
    for (auto& c: t) ++need[c];

    int count = 0, pos = -1, len = std::numeric_limits<int>::max();

    for (int i = 0, j = 0; i < n; ++i) {
      ++window[s[i]];
      if (need[s[i]] >= window[s[i]]) ++count;

      while (count == m) {
        if (i - j + 1 < len) {
          len = i - j + 1;
          pos = j;
        }
        if (need[s[j]] >= window[s[j]]) --count;
        --window[s[j++]];
      }
    }
    return pos < 0 ? "" : s.substr(pos, len);
  }
};
