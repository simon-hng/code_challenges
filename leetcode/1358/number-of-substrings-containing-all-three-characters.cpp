#include <array>
#include <string>

class Solution {
 private:
  auto check_freq(const std::array<int, 3> &freq) -> bool {
    for (auto &f : freq) {
      if (f == 0) return false;
    };
    return true;
  };

 public:
  auto numberOfSubstrings(std::string s) -> int {
    std::array<int, 3> freq = {0, 0, 0};
    int left{0}, right{0};

    int result{0};
    while (right < s.size()) {
      ++freq[s[right] - 'a'];
      while (check_freq(freq)) {
        result += s.size() - right;
        --freq[s[left++] - 'a'];
      }
      ++right;
    }

    return result;
  }
};
