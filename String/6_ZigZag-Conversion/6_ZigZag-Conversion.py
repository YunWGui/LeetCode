"""
 * Title:
 *     6. ZigZag Conversion
 *     6. Z 字形变换
 * Address: 
 *     https://leetcode-cn.com/problems/zigzag-conversion/
"""

# 方法一：
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        
        strs = ["" for _ in range(numRows)]
        row = 0
        flag = 0
        
        for ch in s:
            strs[row] += ch 
            
            if row == 0:
                flag = 1
            elif row == numRows - 1:
                flag = -1
            
            row += flag 
        
        return "".join(strs)
        