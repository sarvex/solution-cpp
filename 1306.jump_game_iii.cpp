class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q{{start}};
        while (not q.empty()) {
            int i = q.front();
            q.pop();
            if (arr[i] == 0) {
                return true;
            }
            int x = arr[i];
            arr[i] = -1;
            for (int j : {i + x, i - x}) {
                if (j >= 0 and j < arr.size() and ~arr[j]) {
                    q.push(j);
                }
            }
        }
        return false;
    }
};