#include <string>
#include <vector>

using std::string;
using std::vector;


    class Solution {
public:
  int countCharacters(const vector<string>& words, const string& chars) {
    int_fast32_t cnt[26]{};
    for (char &c : chars) {
      ++cnt[c - 'a'];
    }
    int ans = 0;
    for (auto &w : words) {
      int_fast32_t wc[26]{};
      bool ok = true;
      for (auto &c : w) {
        int i = c - 'a';
        if (++wc[i] > cnt[i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans += w.size();
      }
    }
    return ans;
  }
};
