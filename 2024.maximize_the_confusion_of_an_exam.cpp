#include <string>

using std::string;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return std::max(get('T', k, answerKey), get('F', k, answerKey));
    }

    int get(char c, int k, string& answerKey) {
        int l = 0, r = 0;
        while (r < answerKey.size()) {
            if (answerKey[r++] == c) --k;
            if (k < 0 and answerKey[l++] == c) ++k;
        }
        return r - l;
    }
};
