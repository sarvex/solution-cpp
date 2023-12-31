#include <string>
#include <vector>

class Trie {
  std::vector<Trie*> children_{};
  int index_;

public:
  Trie() :
    children_(26), index_(0) {}


  void insert(const std::string& word, const int index) {
    auto node = this;
    for (auto& ch: word) {
      const int c = ch - 'a';
      if (not node->children_[c]) node->children_[c] = new Trie();
      node = node->children_[c];
    }
    node->index_ = index;
  }

  [[nodiscard]] auto search(const std::string& word, const int i, const int j) const {
    auto node = this;
    for (int k = j; k >= i; --k) {
      const int idx = word[k] - 'a';
      if (not node->children_[idx]) { return 0; }
      node = node->children_[idx];
    }
    return node->index_;
  }
};

class Solution {
public:
  std::vector<std::vector<int>> palindromePairs(const std::vector<std::string>& words) {
    const int n = words.size();
    Trie trie;

    for (int i = 0; i < n; ++i) trie.insert(words[i], i);

    std::vector<std::vector<int>> result;

    const auto palindrome = [&](const std::string& word, const int start, const int end) {
      for (int i = start, j = end; i < j; ++i, --j) if (word[i] != word[j]) return false;
      return true;
    };

    for (int i = 0; i < n; ++i) {
      const std::string& word = words[i];
      const int m = word.size();
      for (int j = 0; j <= m; ++j) {
        if (palindrome(word, j, m - 1)) {
          if (const int k = trie.search(word, 0, j - 1); k != 0 and k != i) result.push_back({ i, k });
        }
        if (j != 0 and palindrome(word, 0, j - 1)) {
          if (const int k = trie.search(word, j, m - 1); k != 0 and k != i) result.push_back({ k, i });
        }
      }
    }
    return result;
  }
};
