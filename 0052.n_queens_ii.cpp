#include <bitset>
#include <functional>

class Solution {
public:
  auto totalNQueens(const int n) {
    std::bitset<10> cols;
    std::bitset<20> dg;
    std::bitset<20> udg;
    int result = 0;
    std::function<void(int)> search = [&](const int i) {
      if (i == n) {
        ++result;
        return;
      }
      for (int j = 0; j < n; ++j) {
        if (const int a = i + j, b = i - j + n; not cols[j] and not dg[a] and not udg[b]) {
          cols[j] = dg[a] = udg[b] = true;
          search(i + 1);
          cols[j] = dg[a] = udg[b] = false;
        }
      }
    };
    search(0);
    return result;
  }
};
