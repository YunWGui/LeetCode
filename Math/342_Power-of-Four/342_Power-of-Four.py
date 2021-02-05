"""
 * Title:
 *     342. Power of Four
 *     342. 4的幂
 * Address:
 *     https://leetcode-cn.com/problems/power-of-four/
"""

# 方法一：
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False
        elif n == 1:
            return True
        else:
            temp = 1
            while temp < n:
                temp *= 4

            return temp == n

# 方法二：
class Solution_2:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False
        else:
            while n % 4 == 0:
                n /= 4
            return n == 1
