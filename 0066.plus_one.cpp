#include <vector>

using std::vector;

class Solution {
public:
  auto plusOne(vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; --i) {
      ++digits[i];
      digits[i] %= 10;
      if (digits[i] != 0)
        return digits;
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};
