#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  auto minJumpsFast(const std::vector<int>& arr) {
    const auto n = arr.size();

    std::unordered_map<int, std::vector<int>> index;
    for (int i = 0; i < n; i++) index[arr[i]].push_back(i);

    std::queue<int> q;
    std::vector<int> visited(n, false);
    q.push(0);
    visited[0] = true;

    const auto check = [&n](const int i) { return i > 0 and i < n; };
    int step = 0;
    while (not q.empty()) {
      const auto size = q.size();
      for (int k = 0; k < size; k++) {
        const int node = q.front();
        q.pop();
        if (node == n - 1) return step;
        if (int next = node + 1; check(next) and not visited[next]) {
          q.push(next);
          visited[next] = true;
        }
        if (int previous = node - 1; check(previous) and not visited[previous]) {
          q.push(previous);
          visited[previous] = true;
        }
        if (index.contains(arr[node])) {
          for (auto elem: index[arr[node]]) {
            if (check(elem) and not visited[elem]) {
              q.push(elem);
              visited[elem] = true;
            }
          }
          index.erase(arr[node]);
        }
      }
      ++step;
    }
    [[unlikely]] return -1;
  }


  auto minJumps(const std::vector<int>& arr) {
    std::unordered_map<int, std::vector<int>> idx;
    const auto n = arr.size();
    for (int i = 0; i < n; ++i) idx[arr[i]].push_back(i);
    std::queue<std::pair<int, int>> q;
    q.emplace(0, 0);
    std::unordered_set seen{ 0 };
    while (not q.empty()) {
      const auto elem = q.front();
      const int i = elem.first;
      int step = elem.second;
      q.pop();
      if (i == n - 1) return step;
      const int v = arr[i];
      ++step;
      if (idx.contains(v)) {
        for (int j: idx[v]) {
          if (not seen.contains(j)) {
            seen.insert(j);
            q.emplace(j, step);
          }
        }
        idx.erase(v);
      }
      if (i + 1 < n and not seen.contains(i + 1)) {
        seen.insert(i + 1);
        q.emplace(i + 1, step);
      }
      if (i > 0 and not seen.contains(i - 1)) {
        seen.insert(i - 1);
        q.emplace(i - 1, step);
      }
    }
    [[unlikely]] return -1;
  }
};
