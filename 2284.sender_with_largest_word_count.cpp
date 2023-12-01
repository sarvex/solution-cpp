class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> cnt;
        int n = senders.size();
        for (int i = 0; i < n; ++i) {
            int v = count(messages[i].begin(), messages[i].end(), ' ') + 1;
            cnt[senders[i]] += v;
        }
        string ans = senders[0];
        for (auto& [sender, v] : cnt) {
            if (cnt[ans] < v or (cnt[ans] == v and ans < sender)) {
                ans = sender;
            }
        }
        return ans;
    }
};