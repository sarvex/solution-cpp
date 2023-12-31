#include <functional>
#include <queue>
#include <vector>

class Solution {
public:
  int snakesAndLaddersFast(std::vector<std::vector<int>>& board) {
    std::queue<int> q;
    q.push(1);
    const int n = board.size();

    const int goal = n * n;
    int result = 0;

    while (! q.empty()) {
      int count = q.size();
      ++result;
      while (count-- > 0) {
        const int x = q.front();
        q.pop();
        for (int j = 1; j <= 6; ++j) {
          int y = x + j;
          if (y > goal) continue;

          const int r = (y - 1) / n, c = (y - 1) % n;
          int& val = board[n - 1 - r][(r % 2 == 0) ? c : (n - 1 - c)];
          if (val == 0) continue;
          if (val > 0) y = val;
          if (y == goal) return result;
          val = 0;
          q.push(y);
        }
      }
    }
    return -1;
  }

  int snakesAndLadders(std::vector<std::vector<int>>& board) {
    const int n = board.size();

    const auto get = [&](const int x) {
      const int i = (x - 1) / n;
      int j = (x - 1) % n;
      if (i % 2 == 1) j = n - 1 - j;
      return { n - 1 - i, j };
    };

    std::queue<int> q{ { 1 } };
    std::vector<bool> vis(n * n + 1);
    vis[1] = true;
    int result = 0;
    while (! q.empty()) {
      for (int t = q.size(); t; --t) {
        const int curr = q.front();
        if (curr == n * n) return result;
        q.pop();
        for (int k = curr + 1; k <= std::min(curr + 6, n * n); ++k) {
          auto p = get(k);
          int next = k;
          const int i = p[0], j = p[1];
          if (board[i][j] != -1) next = board[i][j];
          if (! vis[next]) {
            vis[next] = true;
            q.push(next);
          }
        }
      }
      ++result;
    }
    return -1;
  }
};
