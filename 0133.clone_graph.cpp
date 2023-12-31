#include <functional>
#include <unordered_map>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }

  explicit Node(const int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }

  Node(const int _val, const std::vector<Node*>& _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
  std::unordered_map<Node*, Node*> visited_;

public:
  Node* cloneGraphFast(Node* node) {
    if (not node)return nullptr;

    std::vector<Node*> visited(101, nullptr);

    std::function<Node*(Node*)> helper = [&](Node* node) {
      const auto clone = new Node(node->val);
      visited[node->val] = clone;
      std::vector<Node*> neighbours;

      for (const auto neighbor: node->neighbors) {
        if (visited[neighbor->val])neighbours.push_back(visited[neighbor->val]);
        else neighbours.push_back(helper(neighbor));
      }
      clone->neighbors = neighbours;
      return clone;
    };

    return helper(node);
  }


  Node* cloneGraph(Node* node) {
    if (not node) return nullptr;
    if (visited_.contains(node)) return visited_[node];
    const auto clone = new Node(node->val);
    visited_[node] = clone;
    for (const auto& neighbor: node->neighbors) clone->neighbors.push_back(cloneGraph(neighbor));
    return clone;
  }
};
