#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool hasDuplicate(std::vector<int>& nums) {
    std::unordered_map<int, int> numToCount{};
    for (auto num : nums) {
      numToCount[num]++;
    }

    for (auto& [_, count] : numToCount) {
      if (count > 1) {
        return true;  // Found a duplicate
      }
    }
    return false;
  }
};
