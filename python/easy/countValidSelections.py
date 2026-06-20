from typing import List


class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        prefix: list[int] = list()
        prefix.append(0)
        for index, value in enumerate(nums):
            prefix.append(prefix[index] + value)
        sum: int = prefix[len(prefix) - 1]
        rs: int = 0
        for index, value in enumerate(nums):
            if value == 0:
                if abs((sum - prefix[index]) - prefix[index]) == 0:
                    rs += 2
                elif abs((sum - prefix[index]) - prefix[index]) == 1:
                    rs += 1
                elif (sum - prefix[index] - prefix[index] < -1):
                    return rs
        return rs


s = Solution()
rs: int = s.countValidSelections([1,0,2,0,3])
print(rs)
