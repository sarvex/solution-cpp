#include <functional>
#include <unordered_map>

class Solution {
public:
  auto canTraverseAllPairs(const std::vector<int>& nums) {
    std::unordered_map<int, std::vector<int>> prime_index;
    std::unordered_map<int, std::vector<int>> index_prime;

    std::vector visited_index(nums.size(), 0);
    std::unordered_map<int, bool> visited_prime;

    const std::function<void(int)> search = [&](const int index) {
      if (visited_index[index] == true) return;
      visited_index[index] = true;

      for (auto& prime: index_prime[index]) {
        if (visited_prime[prime] == true) continue;
        visited_prime[prime] = true;
        for (const auto& elem: prime_index[prime]) {
          if (visited_index[elem] == true) continue;
          search(elem);
        }
      }
    };

    for (int i = 0; i < nums.size(); i++) {
      int temp = nums[i];
      for (int j = 2; j * j <= nums[i]; j++) {
        if (temp % j == 0) {
          prime_index[j].push_back(i);
          index_prime[i].push_back(j);
          while (temp % j == 0) temp /= j;
        }
      }
      if (temp > 1) {
        prime_index[temp].push_back(i);
        index_prime[i].push_back(temp);
      }
    }

    search(0);

    for (const int index : visited_index)
      if (index == false) return false;
    return true;
  }
};
