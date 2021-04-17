"""
 * Title:
 *     73. Set Matrix Zeroes
 *     73. 矩阵置零
 * Address:
 *     https://leetcode-cn.com/problems/set-matrix-zeroes/
"""

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows, cols = len(matrix), len(matrix[0])
       
        # step 1 : 记录所有 0 点的坐标位置
        zero_coordinate = list()
        for row in range(rows):
            for col in range(cols):
                if matrix[row][col] == 0:
                    zero_coordinate.append([row, col])
       
        # step 2 : 遍历，对每个 0 点坐标的行、列分别进行置零操作
        for (row, col) in zero_coordinate:
            for r in range(rows):
                matrix[r][col] = 0
            for c in range(cols):
                matrix[row][c] = 0
        