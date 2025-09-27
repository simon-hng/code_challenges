#include <vector>

class Solution {
 public:
  int numberOfAlternatingGroups(std::vector<int>& colors) {
    auto result{0};
    for (int i{0}; i < colors.size(); ++i) {
      auto second = (i + 1) % colors.size();
      auto third = (i + 2) % colors.size();
      if (colors[i] != colors[second] && colors[second] != colors[third]) {
        ++result;
      }
    }

    return result;
  }
};
