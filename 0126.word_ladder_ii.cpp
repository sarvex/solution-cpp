#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  std::vector<std::vector<std::string>> ans;
  std::unordered_map<std::string, std::unordered_set<std::string>> prev;

public:
  std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string> wordList) {
    std::unordered_set<std::string> words(wordList.cbegin(), wordList.cend());
        if (not words.contains(endWord)) {
            return ans;
        }
        words.erase(beginWord);
        std::unordered_map<std::string, int> dist;
        dist[beginWord] = 0;
        std::queue<std::string> q;
        q.push(beginWord);
        bool found = false;
        int step = 0;
        while (not q.empty() and not found) {
            ++step;
            for (int i = q.size(); i > 0; --i) {
                std::string chars = q.top();
                for (int j = 0; j < chars.length; ++j) {
                    char ch = chars[j];
                    for (char k = 'a'; k <= 'z'; ++k) {
                        chars[j] = k;
                        std::string t = new std::string(chars);
                        if (dist.getOrDefault(t, 0) == step) {
                            prev.get(t).add(p);
                        }
                        if (not words.contains(t)) {
                            continue;
                        }
                        prev.computeIfAbsent(t, key -> new HashSet<>()).add(p);
                        words.remove(t);
                        q.offer(t);
                        dist.put(t, step);
                        if (endWord.equals(t)) {
                            found = true;
                        }
                    }
                    chars[j] = ch;
                }
            }
        }
        if (found) {
            Deque<std::string> path = new ArrayDeque<>();
            path.add(endWord);
            dfs(path, beginWord, endWord);
        }
        return ans;
    }

  void dfs(const std::deque<std::string>& path, const std::string& beginWord, const std::string& cur) {
        if (cur == beginWord) {
            ans.emplace_back(path);
            return;
        }
        for (std::string precursor : prev.get(cur)) {
            path.addFirst(precursor);
            dfs(path, beginWord, precursor);
            path.removeFirst();
        }
    }
}
