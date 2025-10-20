from typing import List, Tuple
from collections import defaultdict
import heapq


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_to_count = defaultdict(int)
        for num in nums:
            num_to_count[num] += 1

        heap: List[Tuple[int, int]] = []
        for num in num_to_count:
            heapq.heappush(heap, (num_to_count[num], num))

            if len(heap) > k:
                heapq.heappop(heap)

        return [heapq.heappop(heap)[1] for _ in range(k)]
