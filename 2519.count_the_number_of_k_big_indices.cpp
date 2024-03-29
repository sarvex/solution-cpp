class BinaryIndexedTree {
public:
    BinaryIndexedTree(int n)
        : size_(n)
        , c(n + 1) {}

    void update(int x, int delta) {
        while (x <= size_) {
            c[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int size_;
    vector<int> c;
};

class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        int n = nums.size();
        BinaryIndexedTree* tree1 = new BinaryIndexedTree(n);
        BinaryIndexedTree* tree2 = new BinaryIndexedTree(n);
        for (int& v : nums) {
            tree2->update(v, 1);
        }
        int ans = 0;
        for (int& v : nums) {
            tree2->update(v, -1);
            ans += tree1->query(v - 1) >= k and tree2->query(v - 1) >= k;
            tree1->update(v, 1);
        }
        return ans;
    }
};