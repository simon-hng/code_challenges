#include <queue>

class Solution {
 public:
  int orangesRotting(std::vector<std::vector<int>>& grid) {
    int fresh{0};
    std::queue<std::pair<int, int>> q;

    for (int i{0}; i < grid.size(); ++i) {
      for (int j{0}; j < grid[i].size(); ++j) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        } else if (grid[i][j] == 1) {
          ++fresh;
        }
      }
    }

    int minutes{0};
    while (fresh && !q.empty()) {
      int length = q.size();
      for (int i{0}; i < length; ++i) {
        auto [r, c] = q.front();
        q.pop();

        const std::array<std::pair<int, int>, 4> directions = {
            {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
        for (const auto& dir : directions) {
          int row = r + dir.first;
          int col = c + dir.second;

          if (row >= 0 && row < grid.size() && col >= 0 &&
              col < grid[0].size() && grid[row][col] == 1) {
            grid[row][col] = 2;
            q.push({row, col});
            --fresh;
          }
        }
      }

      ++minutes;
    }

    return fresh ? -1 : minutes;
  }
};
