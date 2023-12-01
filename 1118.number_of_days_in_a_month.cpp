class Solution {
public:
    int numberOfDays(int year, int month) {
        bool leap = (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0);
        vector<int> days = {0, 31, leap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return days[month];
    }
};