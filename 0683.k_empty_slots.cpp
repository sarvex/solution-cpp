class BinaryIndexedTree {
public:
    int size_;
    vector<int> c;

    BinaryIndexedTree(int n)
        : size_(n)
        , c(n + 1) {}

    void update(int x, int delta) {
        for (; x <= size_; x += x & -x) {
            c[x] += delta;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        BinaryIndexedTree* tree = new BinaryIndexedTree(n);
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; ++i) {
            int x = bulbs[i - 1];
            tree->update(x, 1);
            vis[x] = true;
            int y = x - k - 1;
            if (y > 0 and vis[y] and tree->query(x - 1) - tree->query(y) == 0) {
                return i;
            }
            y = x + k + 1;
            if (y <= n and vis[y] and tree->query(y - 1) - tree->query(x) == 0) {
                return i;
            }
        }
        return -1;
    }
};