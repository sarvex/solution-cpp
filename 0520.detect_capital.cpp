class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (char c : word)
            if (isupper(c)) ++cnt;
        return cnt == 0 or cnt == word.size() or (cnt == 1 and isupper(word[0]));
    }
};