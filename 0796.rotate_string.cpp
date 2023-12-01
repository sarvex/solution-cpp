class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() and strstr((s + s).data(), goal.data());
    }
};