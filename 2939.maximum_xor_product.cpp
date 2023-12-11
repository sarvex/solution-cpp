class Solution {
public:
  auto maximumXorProduct(long long a, long long b, int n) -> int {
    const int mod = 1e9 + 7;
    long long ax = (a >> n) << n, bx = (b >> n) << n;
    for (int i = n - 1; ~i; --i) {
      int x = a >> i & 1, y = b >> i & 1;
      if (x == y) {
        ax |= 1LL << i;
        bx |= 1LL << i;
      } else if (ax < bx) {
        ax |= 1LL << i;
      } else {
        bx |= 1LL << i;
      }
    }
    ax %= mod;
    bx %= mod;
    return ax * bx % mod;
  }
};
