class Solution {
public:
  bool isPowerOfTwo(const int n) { return n > 0 and (n & n - 1) == 0; }
};
