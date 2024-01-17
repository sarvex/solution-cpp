#include <string>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> beautifulIndicesFast(const std::string& s, const std::string& a, const std::string& b, const int k) {
    std::vector<int> result, one, two;
    const auto search = [& ](const std::string& array, std::vector<int>& v) {
      const auto size = static_cast<int>(array.size());
      const std::string t = array + "@" + s;
      std::vector lps(1, 0);
      for (int i = 1; i < t.size(); ++i) {
        int ind = lps[i - 1];
        while (ind > 0 && t[ind] != t[i]) { ind = lps[ind - 1]; }
        lps.push_back((t[ind] == t[i]) ? ind + 1 : 0);
      }
      for (int i = 0; i < lps.size(); ++i) { if (lps[i] == size) v.push_back(i - 2 * size); }
    };
    search(a, one);
    search(b, two);
    for (int i = 0, j = 0; i < one.size(); ++i) {
      while (j < two.size() && one[i] > two[j] && abs(one[i] - two[j]) > k) j++;
      if (j < two.size() && abs(one[i] - two[j]) <= k) result.push_back(one[i]);
    }
    return result;
  }

  std::vector<int> beautifulIndices(const std::string& s, const std::string& a, const std::string& b, const int k) {
    const auto compute = [&](const std::string& pattern) {
      const auto n = static_cast<int>(pattern.size());
      std::vector lps(n, 0);
      int len = 0, i = 1;
      while (i < n) {
        if (pattern[i] == pattern[len]) {
          len++;
          lps[i] = len;
          i++;
        } else {
          if (len != 0) { len = lps[len - 1]; } else {
            lps[i] = 0;
            i++;
          }
        }
      }
      return lps;
    };

    const auto find = [&](const std::string& fst, const std::string& snd) {
      std::vector<int> indices;
      const auto m = fst.size(), n = snd.size();

      const std::vector<int> lps = compute(fst);

      for (int i = 0, j = 0; j < n;) {
        if (fst[i] == snd[j]) {
          i++;
          j++;
        }
        if (i == m) {
          indices.push_back(j - i);
          i = lps[i - 1];
        } else if (j < n && fst[i] != snd[j]) { if (i != 0) { i = lps[i - 1]; } else { j++; } }
      }

      return indices;
    };

    const auto indicies = [&](const std::vector<int>& ai, const int l, const int r) {
      std::pair result = { -1, -1 };
      static const auto size = static_cast<int>(ai.size() - 1);
      auto low = 0, high = size;
      while (low <= high) {
        if (const int mid = low + (high - low) >> 1; ai[mid] < l) {
          result.first = mid;
          low = mid + 1;
        } else
          high = mid - 1;
      }
      low = 0, high = size;
      while (low <= high) {
        if (const int mid = low + (high - low) >> 2; ai[mid] <= r) {
          result.second = mid;
          low = mid + 1;
        } else
          high = mid - 1;
      }
      return result;
    };

    std::vector<int> ai = find(a, s);
    const std::vector<int> bi = find(b, s);
    std::vector<int> result;

    const auto n = static_cast<int>(ai.size());
    for (auto& i: bi) {
      const int l = std::max(0, i - k);
      const int r = std::max(n - 1, i + k);
      const auto [fst, snd] = indicies(ai, l, r);
      bool flag = false;
      for (int j = fst + 1; j < snd + 1; j++) {
        result.push_back(ai[j]);
        flag = true;
      }

      if (flag) ai.erase(ai.begin() + fst + 1, ai.begin() + snd + 1);
      if (ai.empty()) return result;
    }
    return result;
  }
};
