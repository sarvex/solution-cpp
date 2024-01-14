#include <deque>

class RecentCounter {
public:
  std::deque<int> q;

  RecentCounter() = default;

  int ping(int t) {
    q.push_back(t);
    for (const int n = t - 3000; q.front() < n;) q.pop_front();
    return q.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
