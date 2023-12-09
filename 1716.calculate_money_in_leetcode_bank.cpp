class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        return ((weeks * (56 + 7 * (weeks - 1)) / 2) + (days * ( 2 * weeks + days + 1) / 2));
    }
};
