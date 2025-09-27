#include <string>
#include <unordered_map>

class Solution {
 public:
  bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char, int> charCount{};

    for (auto &c : s) {
      charCount[c]++;
    }

    for (auto &c : t) {
      charCount[c]--;
    }

    for (auto &[c, count] : charCount) {
      if (count != 0) {
        return false;  // Found a character with a non-zero count
      }
    }

    return true;
  }
};
