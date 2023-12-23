#include <cstdlib>
#include <unordered_map>
#include <vector>

class RandomizedSet {
public:
  RandomizedSet() = default;

  bool insert(int val) {
    if (index_.contains(val)) return false;
    index_[val] = list_.size();
    list_.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (not index_.contains(val)) return false;
    const int i = index_[val];
    index_[list_.back()] = i;
    list_[i] = list_.back();
    list_.pop_back();
    index_.erase(val);
    return true;
  }

  int getRandom() { return list_[std::rand() % list_.size()]; }

private:
  std::unordered_map<int, int> index_;
  std::vector<int> list_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
