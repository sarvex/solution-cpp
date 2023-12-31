#include <queue>
#include <vector>

class Solution {
public:
  bool canFinishFast(const int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    std::vector<int> indegree(numCourses);
    std::vector<std::vector<int>> adj(numCourses);

    for (auto& prerequisite: prerequisites) {
      adj[prerequisite[1]].push_back(prerequisite[0]); //create vector of outdegree of current node
      indegree[prerequisite[0]]++; //increment the number of indegree of current node
    }

    std::deque<int> q;

    for (int i = 0; i < indegree.size(); i++) { if (indegree[i] == 0) { q.push_back(i); } }

    int visited = 0;
    while (! q.empty()) {
      const int current = q.front();
      std::vector<int> degree = adj[current];

      q.pop_front();
      visited++;

      for (auto& outdegree: degree) {
        indegree[outdegree]--;
        if (indegree[outdegree] == 0) { q.push_back(outdegree); }
      }
    }

    return visited == numCourses;
  }

    bool canFinish(const int numCourses, const std::vector<std::vector<int>>& prerequisites)
    {
      std::vector<std::vector<int>> g(num_courses);
      std::vector<int> index(num_courses);
      for (auto& p: prerequisites) {
        const int a = p[0], b = p[1];
        g[b].push_back(a);
        ++index[a];
      }
      std::queue<int> q;
      for (int i = 0; i < num_courses; ++i) if (index[i] == 0) q.push(i);
      int count = 0;
      while (not q.empty()) {
        const int i = q.front();
        q.pop();
        ++count;
        for (int j: g[i]) if (--index[j] == 0) q.push(j);
      }
      return count == num_courses;
    }
  };
