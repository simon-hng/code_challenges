from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = set()

        if len(nums) == 0:
            return 0
        high, low = nums[0], nums[0]

        for num in nums:
            seen.add(num)
            high = max(high, num)
            low = min(low, num)

        longest = 0
        max_longest = 0
        for i in range(low, high + 1):
            if i in seen:
                longest += 1
            else:
                longest = 0

            max_longest = max(max_longest, longest)

        return max_longest
