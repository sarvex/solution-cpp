#include <functional>
#include <string>
#include <vector>

class Trie {
public:
  std::vector<Trie*> children;
  int ref;

  Trie() : children(26, nullptr), ref(-1) {}

  void insert(const std::string& word, int ref) {
    auto node = this;
    for (char c: word) {
      c -= 'a';
      if (not node->children[c]) { node->children[c] = new Trie(); }
      node = node->children[c];
    }
    node->ref = ref;
  }
};

class Solution {
public:
  auto findWords(std::vector<std::vector<char>>& board, const std::vector<std::string>& words) {
    const auto tree = new Trie();
    for (int i = 0; i < words.size(); ++i) { tree->insert(words[i], i); }
    std::vector<std::string> result;
    const int m = board.size(), n = board[0].size();

    std::function<void(Trie*, int, int)> search = [&](Trie* node, const int i, const int j) {
      const int idx = board[i][j] - 'a';
      if (not node->children[idx]) { return; }
      node = node->children[idx];
      if (node->ref != -1) {
        result.emplace_back(words[node->ref]);
        node->ref = -1;
      }
      constexpr std::vector dirs{ -1, 0, 1, 0, -1 };
      char c = board[i][j];
      board[i][j] = '#';
      for (int k = 0; k < 4; ++k) {
        if (const int x = i + dirs[k], y = j + dirs[k + 1];
          x >= 0 and x < m and y >= 0 and y < n and board[x][y] != '#') { search(node, x, y); }
      }
      board[i][j] = c;
    };

    for (int i = 0; i < m; ++i) { for (int j = 0; j < n; ++j) { search(tree, i, j); } }
    return result;
  }
};
