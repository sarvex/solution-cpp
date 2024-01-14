#include <string>
#include <vector>

class Solution {
public:
  auto uniqueLetterString(const std::string& s) {
    std::vector letters(26, std::vector(2, -1));
    const int n = static_cast<int>(s.length());
    int result = 0;

    for (int i = 0; i < n; ++i) {
      const int c = s[i] - 'A';
      result += (i - letters[c][1]) * (letters[c][1] - letters[c][0]);
      letters[c][0] = letters[c][1];
      letters[c][1] = i;
    }
    for (auto& letter: letters) { result += (n - letter[1]) * (letter[1] - letter[0]); }

    return result;
  }

  auto uniqueLetterString(const std::string& s) {
    std::vector<std::vector<int>> letters(26, { -1 });
    for (int i = 0; i < s.size(); ++i) { letters[s[i] - 'A'].push_back(i); }
    int result = 0;
    for (auto& letter: letters) {
      letter.push_back(s.size());
      const int n = letter.size() - 1;
      for (int i = 1; i < n; ++i) result += (letter[i] - letter[i - 1]) * (letter[i + 1] - letter[i]);
    }
    return result;
  }
};
