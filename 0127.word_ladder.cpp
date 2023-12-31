#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
  int ladderLength(const std::string& beginWord, const std::string& endWord, const std::vector<std::string>& wordList) {
    const std::unordered_set words(wordList.begin(), wordList.end());
    if (not words.contains(endWord)) return 0;
    std::queue<std::string> q1{ { beginWord } };
    std::queue<std::string> q2{ { endWord } };
    std::unordered_map<std::string, int> m1;
    std::unordered_map<std::string, int> m2;
    m1[beginWord] = 0;
    m2[endWord] = 0;

    auto extend = [&](std::queue<std::string>& q) {
      for (int i = q.size(); i > 0; --i) {
        std::string s = q.front();
        const int step = m1[s];
        q.pop();
        for (int j = 0; j < s.size(); ++j) {
          const char ch = s[j];
          for (char k = 'a'; k <= 'z'; ++k) {
            s[j] = k;
            if (not words.contains(s) or m1.contains(s)) continue;
            if (m2.contains(s)) return step + 1 + m2[s];
            m1[s] = step + 1;
            q.emplace(s);
          }
          s[j] = ch;
        }
      }
      return -1;
    };

    while (not q1.empty() and not q2.empty()) {
      if (const int t = q1.size() <= q2.size() ? extend(q1) : extend(q2); t != -1)
        return t + 1;
    }
    return 0;
  }
};
