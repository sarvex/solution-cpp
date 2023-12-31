#include <cstddef>
#include <functional>
#include <vector>

class Node {
public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(const bool _val, const bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(const bool _val, const bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {


public:
  Node* construct(const std::vector<std::vector<int>>& grid) {
    std::function<Node*(int, int, int, int)> search = [&](const int a, const int b, const int c, const int d) {
      int zero = 0, one = 0;
      for (int i = a; i <= c; ++i) {
        for (int j = b; j <= d; ++j) {
          if (grid[i][j])
            one = 1;
          else
            zero = 1;
        }
      }
      const bool is_leaf = zero + one == 1;
      const bool val = is_leaf and one;
      const auto node = new Node(val, is_leaf);
      if (is_leaf) return node;
      node->topLeft = search(a, b, (a + c) / 2, (b + d) / 2);
      node->topRight = search(a, (b + d) / 2 + 1, (a + c) / 2, d);
      node->bottomLeft = search((a + c) / 2 + 1, b, c, (b + d) / 2);
      node->bottomRight = search((a + c) / 2 + 1, (b + d) / 2 + 1, c, d);
      return node;
    };

    return search(0, 0, grid.size() - 1, grid[0].size() - 1);
  }
};
