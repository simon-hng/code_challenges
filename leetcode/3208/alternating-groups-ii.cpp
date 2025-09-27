#include <vector>

class Solution {
 public:
  int numberOfAlternatingGroups(std::vector<int>& colors, int k) {
    int len{1};
    int result{0};
    int last_color{colors[0]};

    for (int i{1}; i < colors.size() + k - 1; ++i) {
      int index = i % colors.size();
      if (colors[index] == last_color) {
        len = 1;
      } else {
        ++len;
        if (len >= k) {
          ++result;
        }
      }

      last_color = colors[index];
    }

    return result;
  };
};
