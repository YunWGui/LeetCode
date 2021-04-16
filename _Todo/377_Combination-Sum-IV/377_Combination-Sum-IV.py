"""
 * Title:
 *     377_Combination-Sum-IV
 *     377. 组合总和 Ⅳ
 * Address:
 *     https://leetcode-cn.com/problems/combination-sum-iv/
"""

"""
    【完全背包】
"""

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target + 1)
        dp[0] = 1

        for i in range(target + 1):
            for num in nums:
                if num <= i:
                    dp[i] += dp[i - num]
        
        return dp[target]