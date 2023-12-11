#include <bitset>
#include <string>

using std::bitset;
using std::string;
using std::to_string;

class Solution {
public:
  auto getPermutation(int n, int k) {
    string ans;
    bitset<10> vis;
    for (int i = 0; i < n; ++i) {
      int fact = 1;
      for (int j = 1; j < n - i; ++j)
        fact *= j;
      for (int j = 1; j <= n; ++j) {
        if (vis[j])
          continue;
        if (k > fact)
          k -= fact;
        else {
          ans += to_string(j);
          vis[j] = 1;
          break;
        }
      }
    }
    return ans;
  }
};
