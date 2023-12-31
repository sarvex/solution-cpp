class Trie {
private:
    vector<Trie*> children;
    bool is_end_;

public:
    Trie()
        : children(26)
        , is_end_(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->is_end_ = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            node = node->children[c];
            if (!node->is_end_) return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie = new Trie();
        for (auto w : words) trie->insert(w);
        string ans = "";
        for (auto w : words) {
            if (ans != "" and (ans.size() > w.size() or (ans.size() == w.size() and ans < w))) continue;
            if (trie->search(w)) ans = w;
        }
        return ans;
    }
};