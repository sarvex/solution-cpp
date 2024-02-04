#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::string b;
  std::vector<std::vector<std::string>> result;
  std::unordered_map<std::string, int> map;

  void dfs(std::string end, std::vector<std::string>& seq) {
    if (end == b) {
      std::reverse(seq.begin(), seq.end());
      result.push_back(seq);
      std::reverse(seq.begin(), seq.end());
      return;
    }
    const int steps = map[end], q = static_cast<int>(end.size());
    for (int i = 0; i < q; i++) {
      const auto temp = end[i];
      for (char p = 'a'; p <= 'z'; p++) {
        end[i] = p;
        if (map.contains(end) and map[end] + 1 == steps) {
          seq.push_back(end);
          dfs(end, seq);
          seq.pop_back();
        }
      }
      end[i] = temp;
    }
  }

  std::vector<std::vector<std::string>>
  findLadders(const std::string& beginWord, const std::string& endWord, std::vector<std::string>& wordList) {

    b = beginWord;
    std::unordered_set s(wordList.begin(), wordList.end());
    std::queue<std::string> q;
    q.push({ beginWord });
    map[beginWord] = 1;
    const auto sz = beginWord.size();
    s.erase(beginWord);
    while (not q.empty()) {
      std::string word = q.front();
      const auto steps = map[word];
      q.pop();
      if (word == endWord) break;
      for (int i = 0; i < sz; i++) {
        std::string temp = word;
        for (char p = 'a'; p <= 'z'; p++) {
          temp[i] = p;
          if (s.contains(temp)) {
            s.erase(temp);
            q.push({ temp });
            map[temp] = steps + 1;
          }
        }
      }
    }

    if (map.contains(endWord)) {
      std::vector<std::string> temp;
      temp.push_back(endWord);
      dfs(endWord, temp);
    }
    return result;
  }
};
