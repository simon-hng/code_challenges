#include <map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findWinners(
      std::vector<std::vector<int>>& matches) {
    std::map<int, int> playerToLosses{};

    for (const auto& match : matches) {
      const auto winner = match[0];
      const auto loser = match[1];

      playerToLosses[loser]++;
      if (!playerToLosses.contains(winner)) {
        playerToLosses[winner] = 0;
      }
    };

    std::vector<int> zero, ones;

    for (const auto& [player, losses] : playerToLosses) {
      if (losses == 0) {
        zero.push_back(player);
      } else if (losses == 1)
        ones.push_back(player);
    }

    return {zero, ones};
  }
};
