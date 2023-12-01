class Solution {
public:
    string maxValue(string n, int x) {
        int i = 0;
        if (n[0] != '-')
            for (; i < n.size() and n[i] - '0' >= x; ++i)
                ;
        else
            for (i = 1; i < n.size() and n[i] - '0' <= x; ++i)
                ;
        return n.substr(0, i) + to_string(x) + n.substr(i);
    }
};