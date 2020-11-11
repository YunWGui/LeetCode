/*
Title:
    1277. Count Square Submatrices with All Ones
    1277. 统计全为 1 的正方形子矩阵
Address: 
    https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/
*/


#include <iostream>
#include <vector>
using namespace std;

// 方法一：动态规划
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if ( matrix.empty() )
            return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp( rows, vector<int>( cols ) );
        
        int count = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (row == 0 || col == 0) 
                    dp[row][col] = matrix[row][col];
                else if (matrix[row][col] == 0) 
                    dp[row][col] = 0;
                else 
                    dp[row][col] = min(min(dp[row][col - 1], dp[row - 1][col]), dp[row - 1][col - 1]) + 1;
                
                count += dp[row][col];
            }
        }

        return count;
    }
};


int main()
{
    

    return 0;
}