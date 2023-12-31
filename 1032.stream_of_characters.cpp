class Trie {
public:
    vector<Trie*> children;
    bool is_end_;

    Trie()
        : children(26)
        , is_end_(false) {}

    void insert(string& w) {
        Trie* node = this;
        reverse(w.begin(), w.end());
        for (char& c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->is_end_ = true;
    }

    bool search(string& w) {
        Trie* node = this;
        for (int i = w.size() - 1; ~i; --i) {
            int idx = w[i] - 'a';
            if (!node->children[idx]) {
                return false;
            }
            node = node->children[idx];
            if (node->is_end_) {
                return true;
            }
        }
        return false;
    }
};

class StreamChecker {
public:
    Trie* trie = new Trie();
    string s;

    StreamChecker(vector<string>& words) {
        for (autoand w : words) {
            trie->insert(w);
        }
    }

    bool query(char letter) {
        s += letter;
        return trie->search(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */