#include <vector>

using std::vector;

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.insert(flowerbed.end(), 0);
    for (int i = 1; i < flowerbed.size() - 1; ++i) {
      if (n > 0 and flowerbed[i] == 0 and flowerbed[i - 1] == 0 and
          flowerbed[i + 1] == 0) {
        flowerbed[i] = 1;
        --n;
      }
    }
    return n == 0;
  }
};
