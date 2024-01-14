#include <functional>
#include <string>

using std::string;

class Solution {
public:
  auto maxConsecutiveAnswersFast(const string& answerKey, const int k) {
    const auto n = answerKey.size();
    int result = 0;
    for (int trues = 0, falses = 0, i = 0, j = 0; j < n; ++j) {
      trues += answerKey[j] == 'T';
      falses += answerKey[j] == 'F';
      if (falses <= k or trues <= k) { result = std::max(result, j - i + 1); } else {
        trues -= answerKey[i] == 'T';
        falses -= answerKey[i] == 'F';
        i++;
      }
    }
    return result;
  }

  auto maxConsecutiveAnswers(const string& answerKey, const int k) {
    const int n = static_cast<int>(answerKey.size());
    const auto get = [&](const char& c, int i) {
      int left = 0, right = 0;
      while (right < n) {
        if (answerKey[right++] == c) --i;
        if (i < 0 and answerKey[left++] == c) ++i;
      }
      return right - left;
    };

    return std::max(get('T', k), get('F', k));
  }
};
