#include <functional>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Solution {
public:
  auto braceExpansionII(const std::string& expression) {

    std::set<std::string> s;

    const std::function<void(std::string)> search = [&] (const std::string& exp) {
      auto j = exp.find_first_of('}');
      if (j == std::string::npos) {
        s.insert(exp);
        return;
      }
      auto i = exp.rfind('{', j);
      std::string a = exp.substr(0, i);
      std::string c = exp.substr(j + 1);
      std::stringstream ss(exp.substr(i + 1, j - i - 1));
      std::string b;
      while (getline(ss, b, ',')) search(a + b + c);
    };

    search(expression);
    return std::vector(s.begin(), s.end());
  }
};
