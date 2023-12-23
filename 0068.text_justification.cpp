#include <string>
#include <vector>

class Solution {
public:
  auto fullJustify(const std::vector<std::string>& words, const int maxWidth) {
    const int n = words.size();
    std::vector<std::string> result;
    for (int i = 0; i < n;) {
      std::vector t = { words[i] };
      int count = words[i].size();
      ++i;
      while (i < n and count + 1 + words[i].size() <= maxWidth) {
        count += 1 + words[i].size();
        t.emplace_back(words[i++]);
      }
      if (i == n or t.size() == 1) {
        std::string left = t[0];
        for (int j = 1; j < t.size(); ++j) { left += " " + t[j]; }
        std::string right = std::string(maxWidth - left.size(), ' ');
        result.emplace_back(left + right);
        continue;
      }
      const int space_width = maxWidth - (count - t.size() + 1);
      const int w = space_width / (t.size() - 1);
      const int m = space_width % (t.size() - 1);
      std::string row;
      for (int j = 0; j < t.size() - 1; ++j) { row += t[j] + std::string(w + (j < m ? 1 : 0), ' '); }
      row += t.back();
      result.emplace_back(row);
    }
    return result;
  }
};
