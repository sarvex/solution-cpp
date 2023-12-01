#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using std::vector;
using std::unordered_set;
using std::string;

class Solution {
public:
  static int countWords(const vector<string> &words1, const vector<string> &words2) {

    unordered_set<string> result = {words1.begin(), words1.end()};
    result.insert(words2.begin(), words2.end());
    std::cout << result << std::endl;

    return words1.size() + words2.size() - result.size();

  }
};

auto main () -> int {
  vector<string> words1 = {"leetcode","is","amazing","as","is"};
  vector<string> words2 = {"amazing","leetcode","is"};
  std::cout << Solution::countWords(words1, words2) << std::endl;

  words1 = {"b","bb","bbb"};
  words2 = {"a","aa","aaa"};
  std::cout << Solution::countWords(words1, words2) << std::endl;


  words1 = {"a","ab"};
  words2 = {"a","a","a","ab"};
  std::cout << Solution::countWords(words1, words2) << std::endl;

  return 0;

}
