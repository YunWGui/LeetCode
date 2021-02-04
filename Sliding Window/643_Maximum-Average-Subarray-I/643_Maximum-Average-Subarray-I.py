"""
 * Title:
 *     643. Maximum Average Subarray I
 *     643. 子数组最大平均数 I
 * Address: 
 *     https://leetcode-cn.com/problems/maximum-average-subarray-i/
"""

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)
        
        if k == n:
            return sum(nums) / n
        
        ans = -10001
        curSum = 0

        for i in range(k):
            curSum += nums[i]
        
        ans = curSum  # ans = max(ans, curSum) -> Error

        for i in range(k, n):
            curSum = curSum - nums[i - k] + nums[i]
            ans = max(ans, curSum)
        
        return ans / k