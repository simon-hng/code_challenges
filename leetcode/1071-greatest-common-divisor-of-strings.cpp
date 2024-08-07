#include "../include/bits/stdc++.h"

class Solution {
 public:
  std::string gcdOfStrings(const std::string str1, const std::string str2) {
    if (str1 + str2 != str2 + str1) return "";

    return str1.substr(0, std::gcd(str1.length(), str2.length()));
  }
};
