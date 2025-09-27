#include <vector>

class Solution {
 public:
  double findMaxAverage(const std::vector<int>& nums, int k) {
    int sum{0};
    for (auto i{0}; i < k; ++i) {
      sum += nums[i];
    };

    int maxSum{sum};
    for (auto i{0}; i < nums.size() - k; ++i) {
      sum = sum - nums[i] + nums[i + k];
      maxSum = std::max(maxSum, sum);
    }

    return double(maxSum) / k;
  }
};
