#include "../include/bits/stdc++.h"

class Solution {
 public:
  std::string gcdOfStrings(std::string str1, std::string str2) {
    if (str1 + str2 != str2 + str1) return "";

    return str1.substr(0, std::gcd(str1.length(), str2.length()));
  }
};

int main() {}
