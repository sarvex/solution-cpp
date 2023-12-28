#include <vector>

class Solution {
public:
  int numRollsToTargetFast(const int n, const int k, const int target) {
    constexpr int mod = 1e9 + 7;
    std::vector<int> result(target + 1);
    for(int i = 1; i <= target && i <= k; ++i){
      result[i] = 1;
    }
    int current = std::min(2 * k, target);
    for(int d = 2; d <= n; ++d){
      int slide = 0;
      const int bound = d - 1;
      int left = current - k, right = current - 1;
      for(int i = right; i > left && i >= bound; --i){
        slide = (slide + result[i]) % mod;
      }
      for(int i = current; i >= d; --i, --left, --right){
        if(left >= bound){
          slide = (slide + result[left]) % mod;
        }
        result[i] = slide;
        slide = ((slide - result[right]) % mod + mod) % mod;
      }
      current = std::min(current + k, target);
    }
    return result[target];
  }

  int numRollsToTarget(const int n, const int k, const int target) {
    constexpr int mod = 1e9 + 7;
    std::vector<int> f(target + 1);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
      std::vector<int> g(target + 1);
      for (int j = 1; j <= std::min(target, i * k); ++j) {
        for (int h = 1; h <= std::min(j, k); ++h) { g[j] = (g[j] + f[j - h]) % mod; }
      }
      f = move(g);
    }
    return f[target];
  }
};
