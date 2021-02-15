"""
 * Title:
 *     485. Max Consecutive Ones
 *     485. 最大连续1的个数
 * Address:
 *     https://leetcode-cn.com/problems/max-consecutive-ones/
"""

# 方法一：
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans, cnt = 0, 0

        for element in nums:
            if element == 1:
                cnt += 1
            else:  # element == 0
                ans = max(ans, cnt)
                cnt = 0
        
        ans = max(ans, cnt)

        return ans

# 方法二：
class Solution_2:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        n = len(nums)
        
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]
        
        ans = nums[0]
        for i in range(1, n):
            if nums[i] == 1:
                nums[i] += nums[i - 1]
                ans = max(ans, nums[i])
        
        return ans