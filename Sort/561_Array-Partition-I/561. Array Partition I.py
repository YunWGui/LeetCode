"""
 * Title:
 *     561. Array Partition I
 *     561. 数组拆分 I
 * Address:
 *     https://leetcode-cn.com/problems/array-partition-i/
"""

# 方法一：排序
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        
        ans = 0
        for i in range(0, len(nums), 2):
            ans += nums[i]
        
        return ans

# 方法二：排序
class Solution_2:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()

        return sum(nums[::2])