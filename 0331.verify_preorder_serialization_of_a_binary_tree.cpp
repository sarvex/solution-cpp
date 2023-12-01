class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> stk;
        stringstream ss(preorder);
        string s;
        while (getline(ss, s, ',')) {
            stk.push_back(s);
            while (stk.size() >= 3 and stk[stk.size() - 1] == "#" and stk[stk.size() - 2] == "#" and stk[stk.size() - 3] != "#") {
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
                stk.push_back("#");
            }
        }
        return stk.size() == 1 and stk[0] == "#";
    }
};