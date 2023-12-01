using pii = pair<int, int>;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        int n = days.size();
        int ans = 0, i = 0;
        while (i < n or !q.empty()) {
            if (i < n and apples[i]) q.emplace(i + days[i] - 1, apples[i]);
            while (!q.empty() and q.top().first < i) q.pop();
            if (!q.empty()) {
                auto [t, v] = q.top();
                q.pop();
                --v;
                ++ans;
                if (v and t > i) q.emplace(t, v);
            }
            ++i;
        }
        return ans;
    }
};