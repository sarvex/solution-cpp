#include <algorithm>
#include <limits>

class SegmentTreeNode {
public:
  int start, end, overlap;
  SegmentTreeNode* left,* right;

  SegmentTreeNode(int _start, int _end) :
    start{ _start }, end{ _end }, overlap{ 0 }, left{ nullptr }, right{ nullptr } {}

  int insert(int start_time, int end_time) {
    if (start_time >= end_time) return 0;
    if (start_time >= end) {
      if (right) return right->insert(start_time, end_time);
      right = new SegmentTreeNode(start_time, end_time);
    } else if (end_time <= start) {
      if (left) return left->insert(start_time, end_time);
      left = new SegmentTreeNode(start_time, end_time);
    } else {
      const int x1 = std::min(start_time, start);
      const int x2 = std::max(start_time, start);
      const int y1 = std::min(end_time, end);
      const int y2 = std::max(end_time, end);
      overlap++;
      int result = overlap;
      if (end > end_time) {
        const auto new_right = new SegmentTreeNode(y1, y2);
        new_right->overlap = overlap - 1;
        new_right->right = right;
        right = new_right;
      } else { result = std::max(insert(y1, y2), result); }
      if (start < start_time) {
        const auto new_left = new SegmentTreeNode(x1, x2);
        new_left->overlap = overlap - 1;
        new_left->left = left;
        left = new_left;
      } else { result = std::max(insert(x1, x2), result); }
      start = x2;
      end = y1;
      return result;
    }
    return 0;
  }
};

class MyCalendarThree {
  SegmentTreeNode tree_;
  int ret_;

public:
  MyCalendarThree() :
    tree_{ -1, std::numeric_limits<int>::max() }, ret_{ 0 } {}

  int book(const int startTime, const int endTime) {
    ret_ = std::max(ret_, tree_.insert(startTime, endTime));
    return ret_;
  }
};
