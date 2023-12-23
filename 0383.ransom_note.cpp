#include <vector>

class Solution {
public:
  bool canConstruct(const std::string& ransomNote, const std::string& magazine) {
    std::vector count(26, 0);
    for (const char& c: magazine) { ++count[c - 'a']; }
    for (const char& c: ransomNote) { if (--count[c - 'a'] < 0) { return false; } }
    return true;
  }
};
