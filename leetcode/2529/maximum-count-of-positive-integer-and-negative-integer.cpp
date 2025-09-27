#include <vector>
jinclude <algorithm>

class Solution {
 public:
  int maximumCount(std::vector<int>& nums) {
    int negCount = std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), 0));
    int posCount = std::distance(std::upper_bound(nums.begin(), nums.end(), 0), nums.end());
    return std::max(negCount, posCount);
  }
};
