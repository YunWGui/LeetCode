"""
 * Title:
 *     1486. XOR Operation in an Array
 *     1486. 数组异或操作
 * Address:
 *     https://leetcode-cn.com/problems/xor-operation-in-an-array/
"""

# 方法一：异或
class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        ans = 0
        
        for i in range(0, n):
            ans ^= start + 2 * i 
        
        return ans