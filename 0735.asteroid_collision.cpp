#include <vector>

using std::vector;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> result;
    for (auto asteroid : asteroids) {
      if (result.empty() or asteroid > 0 or result.back() < 0) {
        result.push_back(asteroid);
      } else {
        while (not result.empty() and result.back() > 0 and result.back() < -asteroid)
          result.pop_back();
        if (not result.empty() and result.back() == -asteroid) {
          result.pop_back();
        } else if (result.empty() or result.back() < 0) {
          result.push_back(asteroid);
        }
      }
    }
    return result;
  }
};
