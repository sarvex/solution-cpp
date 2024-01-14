#include <string>
#include <unordered_map>
#include <vector>

class WordFilter {
  std::unordered_map<std::string, int> dictionary_;

public:
  explicit WordFilter(const std::vector<std::string>& words) {
    for (int k = 0; k < words.size(); ++k) {
      std::string w = words[k];
      const int n = static_cast<int>(w.size());
      for (int i = 0; i <= n; ++i) {
        std::string a = w.substr(0, i);
        for (int j = 0; j <= n; ++j) {
          std::string b = w.substr(j, n - j);
          dictionary_[a + "." + b] = k;
        }
      }
    }
  }

  int f(const std::string& pref, const std::string& suff) {
    if (const std::string key = pref + "." + suff; dictionary_.contains(key)) return dictionary_[key];
    return -1;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
