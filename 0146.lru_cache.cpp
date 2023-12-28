#include <unordered_map>

struct Node {
  int k;
  int v;
  Node* prev;
  Node* next;
  Node() : k(0) , v(0) , prev(nullptr) , next(nullptr) {}
  Node(int key, int val) : k(key) , v(val) , prev(nullptr) , next(nullptr) {}
};

class LRUCache {
public:
  explicit LRUCache(const int capacity) : capacity_(capacity) , size_(0) {
    head_ = new Node();
    tail_ = new Node();
    head_->next = tail_;
    tail_->prev = head_;
  }

  int get(int key) {
    if (not cache_.count(key)) return -1;
    Node* node = cache_[key];
    moveToHead(node);
    return node->v;
  }

  void put(int key, int value) {
    if (cache_.count(key)) {
      Node* node = cache_[key];
      node->v = value;
      moveToHead(node);
    } else {
      Node* node = new Node(key, value);
      cache_[key] = node;
      addToHead(node);
      ++size_;
      if (size_ > capacity_) {
        node = removeTail();
        cache_.erase(node->k);
        --size_;
      }
    }
  }

private:
  std::unordered_map<int, Node*> cache_;
  Node* head_;
  Node* tail_;
  int capacity_;
  int size_;

  void moveToHead(Node* node) {
    removeNode(node);
    addToHead(node);
  }

  void removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addToHead(Node* node) {
    node->next = head_->next;
    node->prev = head_;
    head_->next = node;
    node->next->prev = node;
  }

  Node* removeTail() {
    Node* node = tail_->prev;
    removeNode(node);
    return node;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
