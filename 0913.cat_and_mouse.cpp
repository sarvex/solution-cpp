#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
  int catMouseGame(const std::vector<std::vector<int>>& graph) {
    enum class State { draw, mouse, cat };
    const int n = static_cast<int>(graph.size());
    std::vector states(n, std::vector(n, std::vector(2, State::draw)));
    std::vector degrees(n, std::vector(n, std::vector(2, 0)));
    std::queue<std::tuple<int, int, int, State>> q;
    for (int cat = 0; cat < n; ++cat) {
      for (int mouse = 0; mouse < n; ++mouse) {
        const auto hole = std::count(graph[cat].begin(), graph[cat].end(), 0);
        degrees[cat][mouse][0] = static_cast<int>(graph[mouse].size());
        degrees[cat][mouse][1] = static_cast<int>(graph[cat].size()) - static_cast<int>(hole);
      }
    }
    for (int cat = 1; cat < n; ++cat)
      for (int move = 0; move < 2; ++move)
        q.emplace(cat, 0, move, states[cat][0][move] = State::mouse),
            q.emplace(cat, cat, move, states[cat][cat][move] = State::cat);
    while (! q.empty()) {
      const auto [cat, mouse, move, state] = q.front();
      q.pop();
      if ((cat == 2) && (mouse == 1) && (move == 0))
        return static_cast<int>(state);
      const int prev_move = move ^ 1;
      for (const int prev: graph[prev_move ? cat : mouse]) {
        const int prev_cat = prev_move ? prev : cat;
        if (prev_cat == 0) continue;
        const int prev_mouse = prev_move ? mouse : prev;
        if (states[prev_cat][prev_mouse][prev_move] != State::draw) continue;
        if (((prev_move == 0) && (state == State::mouse))
            || ((prev_move == 1) && (state == State::cat))
            || (--degrees[prev_cat][prev_mouse][prev_move] == 0))
          states[prev_cat][prev_mouse][prev_move] = state,
              q.emplace(prev_cat, prev_mouse, prev_move, state);
      }
    }
    return static_cast<int>(states[2][1][0]);
  }
};
