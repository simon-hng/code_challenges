// given an array of strings wordsDict and two strings that already exist in the
// array word1 and word2, return the shortest distance between the occurrence of
// these two words in the list.

// Note that word1 and word2 may be the same. It is guaranteed that they
// represent two individual words in the list.

// Example 1:
// Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1
// = "makes", word2 = "coding" Output: 1

// Example 2:
// Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1
// = "makes", word2 = "makes" Output: 3

// Constraints:

// 1 <= wordsDict.length <= 105
// 1 <= wordsDict[i].length <= 10
// wordsDict[i] consists of lowercase English letters.
// word1 and word2 are in wordsDict.

#include <string>
#include <vector>

class Solution {
 public:
  int shortestWordDistance(std::vector<std::string>& wordsDict,
                          std::string word1, std::string word2) {
    int result = wordsDict.size();

    int index1{-1}, index2{-1};

    for (int i{0}; i < wordsDict.size(); ++i) {
      if (wordsDict[i] == word1) {
        index1 = i;
        if (index2 != -1) {
          result = std::min(result, abs(index1 - index2));
        }
      }
      if (wordsDict[i] == word2) {
        index2 = i;
        if (index1 != -1) {
          result = std::min(result, abs(index1 - index2));
        }
      }
    }

    return result;
  }
};