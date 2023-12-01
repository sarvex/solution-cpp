class Solution {
public:
  static bool isPalindrome(int x) {
    if (x < 0 or (x and x % 10 == 0)) {
      return false;
    }
    auto y = 0;
    for (; y < x; x /= 10) {
      y = y * 10 + x % 10;
    }
    return x == y or x == y / 10;
  }
};
