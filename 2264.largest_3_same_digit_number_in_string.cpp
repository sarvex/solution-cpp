#include <string>

using std::string;


class Solution {
public:
  auto largestGoodIntegerFast(const string& num) {
    string result = "0";
    for (int i = 0; i < num.size()-2; ++i)
        if (num[i] == num[i+1] and num[i] == num[i+2])
            result = max(result, num.substr(i, 3));


    if (result == "0") {
        return "";
    }
    return result;
  }

  auto largestGoodInteger(const string& num) {
    for (char i = '9'; i >= '0'; --i) {
      string s(3, i);
      if (num.find(s) != string::npos) {
        return s;
      }
    }
    return "";
  }
};
