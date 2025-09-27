#include <vector>
#include <algorithm>

class Solution {
 public:
  int minZeroArray(std::vector<int>& nums,
                   std::vector<std::vector<int>>& queries) {
    int k = 0, sum = 0;
    std::vector<int> diff(nums.size() + 1, 0);

    for (int i = 0; i < nums.size(); ++i) {
      while (sum + diff[i] < nums[i]) {
        if (k >= queries.size()) return -1;

        const auto& query = queries[k++];
        int l = query[0], r = query[1], val = query[2];

        if (r >= i) {
          diff[std::max(i, l)] += val;
          diff[r + 1] -= val;
        }
      }
      sum += diff[i];
    }

    return k;
  }
};
