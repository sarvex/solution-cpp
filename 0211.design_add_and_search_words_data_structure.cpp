#include <functional>
#include <string>
#include <vector>

class Trie {
  std::vector<Trie*> children_;
  bool is_end_;
public:
  Trie() {
    children_ = std::vector<Trie*>(26, nullptr);
    is_end_ = false;
  }

  void insert(const std::string& word) {
    auto cur = this;
    for (char c: word) {
      c -= 'a';
      if (cur->children_[c] == nullptr) cur->children_[c] = new Trie;
      cur = cur->children_[c];
    }
    cur->is_end_ = true;
  }
};

class WordDictionary {
  Trie* root_;

public:
  WordDictionary() :
    root_(new Trie) {}

  void addWord(const std::string& word) { root_->insert(word); }

  bool search(const std::string& word) {
    std::function<bool(int, Trie*)> dfs = [&](const int i, const Trie* cur) {
      if (i == word.size()) return cur->is_end_;
      if (auto& c = word[i]; c != '.') {
        if (auto child = cur->children_[c - 'a']; child != nullptr and dfs(i + 1, child)) { return true; }
      } else { for (auto child: cur->children_) { if (child != nullptr and dfs(i + 1, child)) { return true; } } }
      return false;
    };

    return dfs(0, root_);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
