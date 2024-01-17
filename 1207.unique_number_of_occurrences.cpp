#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  static auto uniqueOccurrences(std::vector<int> &arr) {
    const auto n = arr.size();
    for (int i : arr)
      std::cout << i << ' ';
    std::cout << "->" << arr.size() << '\n';
    std::ranges::sort(arr);
    for (int i : arr)
      std::cout << i << ' ';
    std::cout << "->" << arr.size() << '\n';
    arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
    for (int i : arr)
      std::cout << i << ' ';
    std::cout << "->" << arr.size() << '\n';
    return n != arr.size();
  }
};

int main() {
  std::vector array{3, 5, -2, -3, -6, -6};
  Solution::uniqueOccurrences(array);
}
