class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j = 0;
        for (int v : pushed) {
            stk.push(v);
            while (!stk.empty() and stk.top() == popped[j]) {
                stk.pop();
                ++j;
            }
        }
        return j == pushed.size();
    }
};