class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (int& v : arr) {
            if (stk.empty() or stk.top() <= v)
                stk.push(v);
            else {
                int mx = stk.top();
                stk.pop();
                while (!stk.empty() and stk.top() > v) stk.pop();
                stk.push(mx);
            }
        }
        return stk.size();
    }
};