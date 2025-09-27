#include <vector>

class Solution {
 public:
  int longestNiceSubarray(std::vector<int>& nums) {
    int l{0}, curr{0}, result{0};

    for (int r{0}; r < nums.size(); ++r) {
      while (curr & nums[r]) {
        curr ^= nums[l++];
      }
      result = std::max(result, r - l + 1);
      curr |= nums[r];
    }

    return result;
  }
};
