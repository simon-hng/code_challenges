#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numToIndex{};

    for (int i{0}; i < nums.size(); ++i) {
      auto diff = target - nums[i];

      if (numToIndex.find(diff) != numToIndex.end()) {
        return {numToIndex[diff], i};
      }

      numToIndex[nums[i]] = i;
    }

    return {};
  }
};
