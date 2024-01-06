#include <functional>
#include <string>
#include <vector>

class Solution {
public:
  bool existFast(std::vector<std::vector<char>>& board, std::string word) {
    std::unordered_map<char, int> boardCharCount, wordCharCount;
    for (const auto& row : board) {
      for (char ch : row) {
        ++boardCharCount[ch];
      }
    }

    for (char ch : word) {
      ++wordCharCount[ch];
      if (wordCharCount[ch] > boardCharCount[ch]) {
        return false;
      }
    }

    if (boardCharCount[word.back()] < boardCharCount[word.front()]) {
      reverse(word.begin(), word.end());
    }

    const int m = board.size(), n = board[0].size(), o = word.size();
    // DFS function
    std::function<bool(int, int, int)> search = [&](const int x, const int y, const int k) {
      if (k == o) return true;
      if (x < 0 or x >= m or y < 0 or y >= n) return false;
      if (board[x][y] != word[k]) return false;

      const char temp = board[x][y];
      board[x][y] = '#';
      const bool found = search(x + 1, y, k + 1) or search(x - 1, y, k + 1) or
                         search(x, y + 1, k + 1) or search(x, y - 1, k + 1);
      board[x][y] = temp;

      return found;
    };

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (search(i, j, 0)) return true;
      }
    }

    return false;
  }

  auto exist(std::vector<std::vector<char>>& board, const std::string& word) {
    const int m = board.size(), n = board[0].size(), o = word.size() - 1;
    const std::vector dirs = { -1, 0, 1, 0, -1 };
    std::function<bool(int, int, int)> search = [&](const int i, const int j, const int k) {
      if (k == o) return board[i][j] == word[k];
      if (board[i][j] != word[k]) return false;
      const char c = board[i][j];
      board[i][j] = '0';
      for (int d = 0; d < 4; ++d) {
        if (const int x = i + dirs[d], y = j + dirs[d + 1];
          x >= 0 and x < m and y >= 0 and y < n and board[x][y] != '0' and
          search(x, y, k + 1)) return true;
      }
      board[i][j] = c;
      return false;
    };
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (search(i, j, 0)) return true;
    return false;
  }
};
