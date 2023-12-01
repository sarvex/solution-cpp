class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;
        while (true) {
            while (i < n and start[i] == 'X') ++i;
            while (j < n and end[j] == 'X') ++j;
            if (i == n and j == n) return true;
            if (i == n or j == n or start[i] != end[j]) return false;
            if (start[i] == 'L' and i < j) return false;
            if (start[i] == 'R' and i > j) return false;
            ++i;
            ++j;
        }
    }
};