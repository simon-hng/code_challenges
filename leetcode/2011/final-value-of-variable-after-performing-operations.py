from typing import List, Literal


Operation = Literal["++X", "X++", "--X", "X--"]


class Solution:
    def finalValueAfterOperations(self, operations: List[Operation]) -> int:
        x = 0
        for operation in operations:
            match operation:
                case "++X" | "X++":
                    x += 1
                case "--X" | "X--":
                    x -= 1

        return x
