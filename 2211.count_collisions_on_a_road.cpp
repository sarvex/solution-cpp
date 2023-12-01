class Solution {
public:
    int countCollisions(string directions) {
        int l = 0, r = directions.size() - 1, count = 0;
        while (l <= r and directions[l] == 'L') {
            l++;
        }
        while (l <= r and directions[r] == 'R') {
            r--;
        }
        for (int i = l; i <= r; i++) {
            count += directions[i] != 'S';
        }
        return count;
    }
};