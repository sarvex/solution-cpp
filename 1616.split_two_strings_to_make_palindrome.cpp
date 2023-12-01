class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return check1(a, b) or check1(b, a);
    }

private:
    bool check1(string& a, string& b) {
        int i = 0, j = b.size() - 1;
        while (i < j and a[i] == b[j]) {
            ++i;
            --j;
        }
        return i >= j or check2(a, i, j) or check2(b, i, j);
    }

    bool check2(string& a, int i, int j) {
        while (i <= j and a[i] == a[j]) {
            ++i;
            --j;
        }
        return i >= j;
    }
};
