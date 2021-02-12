"""
Title:
    119. Pascal's Triangle II
    119. 杨辉三角 II
Address:
    https://leetcode-cn.com/problems/pascals-triangle-ii/
"""

# 方法一：递推
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        kRows = [i for i in range(rowIndex + 1)]

        for i in range(rowIndex + 1):
            kRows[i] = 1
            
            j = i
            while j > 1:
                kRows[j - 1] = kRows[j - 1] + kRows[j - 2]
                j -= 1
        
        return kRows

# 方法二：线性递推
class Solution_2:
    def getRow(self, rowIndex: int) -> List[int]:
        kRows = [_ for _ in range(rowIndex + 1)]

        kRows[0] = 1
        for i in range(1, rowIndex + 1):
            kRows[i] = kRows[i - 1] * (rowIndex - i + 1) // i 
        
        return kRows