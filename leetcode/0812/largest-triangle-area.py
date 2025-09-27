from typing import List


class Solution:
    def calculateArea(self, points: List[List[int]]) -> float:
        # Shoelace formula for calculating area of a triangle
        x1, y1 = points[0]
        x2, y2 = points[1]
        x3, y3 = points[2]

        area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0)
        return area

    def largestTriangleArea(self, points: List[List[int]]) -> float:
        result = 0
        for p1 in points:
            for p2 in points:
                for p3 in points:
                    result = max(self.calculateArea([p1, p2, p3]), result)

        return result
