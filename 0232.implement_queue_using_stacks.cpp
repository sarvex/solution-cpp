#include <stack>

class MyQueue {
public:
  MyQueue() = default;

  void push(const int x) { stk1_.push(x); }

  int pop() {
    move();
    const int result = stk2_.top();
    stk2_.pop();
    return result;
  }

  int peek() {
    move();
    return stk2_.top();
  }

  [[nodiscard]] bool empty() const { return stk1_.empty() and stk2_.empty(); }

private:
  std::stack<int> stk1_;
  std::stack<int> stk2_;

  void move() {
    if (stk2_.empty()) {
      while (! stk1_.empty()) {
        stk2_.push(stk1_.top());
        stk1_.pop();
      }
    }
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
