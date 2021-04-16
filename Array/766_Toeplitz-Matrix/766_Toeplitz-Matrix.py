"""
Title:
    766. Toeplitz Matrix
    766. 托普利茨矩阵
Address: 
    https://leetcode-cn.com/problems/toeplitz-matrix/
"""

# 方法二：
class Solution_2:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        rows, cols = len(matrix), len(matrix[0])

        for row in range(1, rows):
            for col in range(1, cols):
                if matrix[row][col] != matrix[row - 1][col - 1]:
                    return False
        
        return True

# 方法一：
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        rows, cols = len(matrix), len(matrix[0])

        for col in range(cols):
            row = 0
            r, c = row + 1, col + 1            
            while r < rows and c < cols:
                if matrix[row][col] != matrix[r][c]:
                    return False
                r += 1
                c += 1

        for row in range(1, rows):
            col = 0
            r, c = row + 1, col + 1
            while r < rows and c < cols:
                if matrix[row][col] != matrix[r][c]:
                    return False
                r += 1
                c += 1
        
        return True