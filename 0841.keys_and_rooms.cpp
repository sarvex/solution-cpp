#include <functional>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool canVisitAllRooms(const std::vector<std::vector<int>>& rooms) {
    std::unordered_set<int> seen;
    const std::function<void(int)> search = [&](const int key) -> void {
      if (seen.contains(key)) return;
      seen.insert(key);
      for (auto& room: rooms[key]) search(room);
    };
    search(0);
    return seen.size() == rooms.size();
  }
};
