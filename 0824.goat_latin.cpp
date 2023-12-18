#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class Solution {
public:
  string toGoatLatin(string& sentence) {
    string result;
    const unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    int i = 0, start = 0, end = 0;
    sentence += " ";
    while ( (end = sentence.find(' ', start)) != string::npos) {
      string token = sentence.substr(start, end - start);
      string word;

      if (vowels.contains(token[0]))
        word = token;
      else
        word = token.substr(1) + token[0];

      word.append("ma");
      word.append(++i, 'a');

      result.append(word + " ");
      start = end + 1;
    }

    result.pop_back();
    return result;
  }
};