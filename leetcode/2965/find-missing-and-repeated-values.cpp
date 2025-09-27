#include <vector>

class Solution {
 public:
  std::vector<int> findMissingAndRepeatedValues(
      std::vector<std::vector<int>>& grid) {
    auto n = grid.size();
    std::vector<int> frequencies(n * n, 0);

    for (auto row : grid) {
      for (auto cell : row) {
        frequencies[cell - 1]++;
      }
    }

    std::vector<int> result(2);

    for (int i{0}; i < frequencies.size(); ++i) {
      if (frequencies[i] == 2) {
        result[0] = i + 1;
      } else if (frequencies[i] == 0) {
        result[1] = i + 1;
      }
    }
    return result;
  }
};
