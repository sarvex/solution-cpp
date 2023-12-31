#include <string>
#include <vector>

class Trie {
  std::vector<Trie*> children_;
  bool is_end_;

  Trie* searchPrefix(const std::string& s) {
    auto node = this;
    for (auto& c: s) {
      const int idx = c - 'a';
      if (not node->children_[idx]) return nullptr;
      node = node->children_[idx];
    }
    return node;
  }

public:
  Trie() : children_(26) , is_end_(false) {}

  void insert(const std::string& word) {
    auto node = this;
    for (const auto c: word) {
      const int idx = c - 'a';
      if (! node->children_[idx]) node->children_[idx] = new Trie();
      node = node->children_[idx];
    }
    node->is_end_ = true;
  }

  bool search(const std::string& word) {
    const auto node = searchPrefix(word);
    return node and node->is_end_;
  }

  bool startsWith(const std::string& prefix) {
    const auto node = searchPrefix(prefix);
    return node != nullptr;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
