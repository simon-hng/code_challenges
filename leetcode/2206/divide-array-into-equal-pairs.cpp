#include <array>
#include <vector>

class Solutiona{
 public:
  bool divideArray(std::vector<int>& nums) {
    std::array<int, 501> num_to_freq{};

    for (auto num : nums) {
      num_to_freq[num]++;
    }

    for (auto freq : num_to_freq) {
      if (freq % 2 != 0) {
        return false;
      }
    }

    return true;
  }
};
