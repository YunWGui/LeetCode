"""
 * 题目：
 * 		29. Divide Two Integers
 * 		29. 两数相除
 * 地址：
 * 		https://leetcode-cn.com/problems/divide-two-integers/
"""

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        di = abs(dividend)
        ds = abs(divisor)
        solve = 0

        while ds <= di:
            di -= ds
            solve += 1
        
        if dividend > 0 and divisor > 0:  # 同号
            return solve
        
        if dividend < 0 and divisor < 0:  # 同号
            return solve
        
        return -solve  # 异号
           
        
s = Solution()
#y = s.divide(10, 3)
#y = s.divide(7, -3)
y = s.divide(-2147483648, -1)

print(y)