#include <sstream>
#include <string>

class Solution {
 public:
  std::string reverseWords(std::string s) {
    std::istringstream iss(s);
    std::vector<std::string> words;
    std::string word;

    while (iss >> word) {
      words.push_back(word);
    }

    std::ostringstream oss{};
    oss << words.back();
    words.pop_back();

    while (!words.empty()) {
      oss << " " << words.back();
      words.pop_back();
    }

    return oss.str();
  }
};
