#include <limits>
#include <stack>

class MinStack {
  std::stack<int> stk_;
  std::stack<int> min_;

public:
  MinStack() { min_.push(std::numeric_limits<int>::max()); }

  void push(const int val) {
    stk_.push(val);
    min_.push(std::min(val, min_.top()));
  }

  void pop() {
    stk_.pop();
    min_.pop();
  }

  int top() { return stk_.top(); }

  int getMin() { return min_.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
