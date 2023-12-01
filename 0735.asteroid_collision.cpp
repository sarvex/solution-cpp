class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (int x : asteroids) {
            if (x > 0) {
                stk.push_back(x);
            } else {
                while (stk.size() and stk.back() > 0 and stk.back() < -x) {
                    stk.pop_back();
                }
                if (stk.size() and stk.back() == -x) {
                    stk.pop_back();
                } else if (stk.empty() or stk.back() < 0) {
                    stk.push_back(x);
                }
            }
        }
        return stk;
    }
};