#define CAT 0
#define MOUSE 1
#include <queue>
#include <string>
#include <vector>

class Solution {
public:
  bool canMouseWin(std::vector<std::string>& grid, int catJump, int mouseJump) {
    const int n = grid.size(), m = grid[0].size();
    std::vector result(n, std::vector(m, std::vector(n, std::vector(m, std::vector(2, -1)))));
    std::pair<int, int> cat, mouse, food;

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == 'C') cat = std::make_pair(i, j);
        if (grid[i][j] == 'M') mouse = std::make_pair(i, j);
        if (grid[i][j] == 'F') food = std::make_pair(i, j);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (std::pair it(i, j); grid[i][j] != '#' and food != it) {
          result[i][j][i][j][0] = CAT;
          result[i][j][i][j][1] = CAT;
          result[i][j][food.first][food.second][0] = MOUSE;
          result[i][j][food.first][food.second][1] = MOUSE;
          result[food.first][food.second][i][j][0] = CAT;
          result[food.first][food.second][i][j][1] = CAT;
        }
      }
    }

    for (int turns = 0; turns < 50; ++turns) {
      for (int cx = 0; cx < n; ++cx) {
        for (int cy = 0; cy < m; ++cy) {
          for (int mx = 0; mx < n; ++mx) {
            for (int my = 0; my < m; ++my) {
              if (grid[cx][cy] == '#' or grid[mx][my] == '#') { continue; }

              for (int move = 0; move < 2; move++) {
                if (result[cx][cy][mx][my][move] != -1) { continue; }

                if (move == 0) {
                  bool islost = true;
                  bool up = true,
                       down = true,
                       left = true, right = true;

                  for (int i = 1; i <= mouseJump; ++i) {
                    if (mx + i < n) {
                      if (grid[mx + i][my] == '#') { down = false; }

                      if (down) {
                        if (result[cx][cy][mx + i][my][1] == MOUSE) {
                          result[cx][cy][mx][my][0] = MOUSE;
                          islost = false;
                          break;
                        }
                        if (result[cx][cy][mx + i][my][1] == -1) { islost = false; }
                      }
                    }

                    if (mx - i >= 0) {
                      if (grid[mx - i][my] == '#') { up = false; }

                      if (up) {
                        if (result[cx][cy][mx - i][my][1] == MOUSE) {
                          result[cx][cy][mx][my][0] = MOUSE;
                          islost = false;
                          break;
                        }
                        if (result[cx][cy][mx - i][my][1] == -1) { islost = false; }
                      }
                    }

                    if (my + i < m) {
                      if (grid[mx][my + i] == '#') { right = false; }

                      if (right) {
                        if (result[cx][cy][mx][my + i][1] == MOUSE) {
                          result[cx][cy][mx][my][0] = MOUSE;
                          islost = false;
                          break;
                        }
                        if (result[cx][cy][mx][my + i][1] == -1) { islost = false; }
                      }
                    }

                    if (my - i >= 0) {
                      if (grid[mx][my - i] == '#') { left = false; }

                      if (left) {
                        if (result[cx][cy][mx][my - i][1] == MOUSE) {
                          result[cx][cy][mx][my][0] = MOUSE;
                          islost = false;
                          break;
                        }
                        if (result[cx][cy][mx][my - i][1] == -1) { islost = false; }
                      }
                    }
                  }

                  if (islost and result[cx][cy][mx][my][1] == CAT) { result[cx][cy][mx][my][0] = CAT; }
                } else {
                  bool islost = true;
                  bool up = true,
                       down = true,
                       left = true,
                       right = true;

                  for (int i = 1; i <= catJump; i++) {
                    if (cx + i < n) {
                      if (grid[cx + i][cy] == '#') { down = false; }

                      if (down) {
                        if (result[cx + i][cy][mx][my][0] == CAT) {
                          result[cx][cy][mx][my][1] = CAT;
                          islost = false;
                          break;
                        }
                        if (result[cx + i][cy][mx][my][0] == -1) { islost = false; }
                      }
                    }

                    if (cx - i >= 0) {
                      if (grid[cx - i][cy] == '#') { up = false; }

                      if (up) {
                        if (result[cx - i][cy][mx][my][0] == CAT) {
                          result[cx][cy][mx][my][1] = CAT;
                          islost = false;
                          break;
                        }
                        if (result[cx - i][cy][mx][my][0] == -1) { islost = false; }
                      }
                    }

                    if (cy + i < m) {
                      if (grid[cx][cy + i] == '#') { right = false; }

                      if (right) {
                        if (result[cx][cy + i][mx][my][0] == CAT) {
                          result[cx][cy][mx][my][1] = CAT;
                          islost = false;
                          break;
                        }
                        if (result[cx][cy + i][mx][my][0] == -1) { islost = false; }
                      }
                    }

                    if (cy - i >= 0) {
                      if (grid[cx][cy - i] == '#') { left = false; }

                      if (left) {
                        if (result[cx][cy - i][mx][my][0] == CAT) {
                          result[cx][cy][mx][my][1] = CAT;
                          islost = false;
                          break;
                        }
                        if (result[cx][cy - i][mx][my][0] == -1) { islost = false; }
                      }
                    }
                  }

                  if (islost and result[cx][cy][mx][my][0] == MOUSE) { result[cx][cy][mx][my][1] = MOUSE; }
                }
              }
            }
          }
        }
      }
    }

    std::vector seen(grid.size(), std::vector<int>(grid[0].size(), false));

    if (const auto check = [& ](const std::pair<int, int>& start, const std::pair<int, int>& end) {
      std::queue<std::pair<int, int>> q;
      q.emplace(start);

      while (not q.empty()) {
        const auto elem = q.front();
        q.pop();
        auto& [x, y] = elem;
        if (seen[x][y]) continue;
        seen[x][y] = true;
        if (x + 1 < grid.size() and grid[x + 1][y] != '#') { q.emplace(x + 1, y); }
        if (y + 1 < grid[0].size() and grid[x][y + 1] != '#') { q.emplace(x, y + 1); }
        if (x - 1 >= 0 and grid[x - 1][y] != '#') { q.emplace(x - 1, y); }
        if (y - 1 >= 0 and grid[x][y - 1] != '#') { q.emplace(x, y - 1); }
      }

      return seen[end.first][end.second];
    }; result[cat.first][cat.second][mouse.first][mouse.second][0] == MOUSE and
       check(mouse, food)) { return true; }
    return false;
  }
};
