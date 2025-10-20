from typing import List
from collections import defaultdict


class Solution:
    def groupAnagrams(self, words: List[str]) -> List[List[str]]:
        group_to_strings = defaultdict(list)

        for word in words:
            char_to_count = [0] * 26
            for char in word:
                char_to_count[ord(char) - ord("a")] += 1

            group_to_strings[tuple(char_to_count)].append(word)

        return [words for words in group_to_strings.values()]
