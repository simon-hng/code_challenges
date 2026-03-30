from typing import List


class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums = sorted(nums)
        min_diff = nums[len(nums) - 1]

        for i in range(len(nums) - k + 1):
            min_diff = min(min_diff, abs(nums[i] - nums[i + k - 1]))
        return min_diff
