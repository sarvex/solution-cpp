#include <queue>
#include <vector>

class MedianFinder {
  std::priority_queue<int, std::vector<int>, std::greater<>> large_;
  std::priority_queue<int> small_;

public:
  MedianFinder() {}

  void addNum(const int num) {
    large_.push(num);
    small_.push(large_.top());
    large_.pop();
    if (small_.size() - large_.size() > 1) {
      large_.push(small_.top());
      small_.pop();
    }
  }

  double findMedian() {
    if (small_.size() > large_.size()) return small_.top();
    return static_cast<double>(large_.top() + small_.top()) / 2;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
