#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::unordered_map;
using std::pair;
using std::set;
using std::string;
using std::vector;

class FoodRatings {
  static constexpr auto comp = [](const pair<string, int>& a, const pair<string, int>& b) {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
  };

public:
  unordered_map<string, pair<string, int>> menu;
  unordered_map<string, set<pair<string, int>, decltype(comp)>> rating;

  FoodRatings(const vector<string>& foods, const vector<string>& cuisines, const vector<int>& ratings) {
    for (int i = 0; i < foods.size(); ++i) {
      menu[foods[i]] = { cuisines[i], ratings[i] };
      rating[cuisines[i]].insert({ foods[i], ratings[i] });
    }
  }

  void changeRating(const string& food, const int newRating) {
    auto& [fst, snd] = menu[food];
    auto& r = rating[fst];
    r.erase({ food, snd });
    snd = newRating;
    r.insert({ food, snd });
  }

  string highestRated(const string& cuisine) { return rating[cuisine].begin()->first; }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
