class BinaryIndexedTree {
public:
    int size_;
    vector<int> c;

    BinaryIndexedTree(int n)
        : size_(n + 1e5 + 1)
        , c(n + 1 + 1e5 + 1) {}

    void update(int x, int delta) {
        x += 1e5 + 1;
        while (x <= size_) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        x += 1e5 + 1;
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        x += 1e5 + 1;
        return x & -x;
    }
};

class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + (nums[i] == 1 ? 1 : -1);
        BinaryIndexedTree* tree = new BinaryIndexedTree(n + 1);
        int ans = 0;
        const int MOD = 1e9 + 7;
        for (int v : s) {
            ans = (ans + tree->query(v - 1)) % MOD;
            tree->update(v, 1);
        }
        return ans;
    }
};