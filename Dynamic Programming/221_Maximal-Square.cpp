/*
Title:
    221. Maximal Square
    221. 最大正方形
Address: 
    https://leetcode-cn.com/problems/maximal-square/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
// https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode-solution/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if ( matrix.empty() )
            return 0;
        
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp( rows, vector<int>( cols, 0 ) );

        int maxSide = 0;  // 最大正方形的边
        
        for ( int row = 0; row < rows; ++row ) {
            for ( int col = 0; col < cols; ++col ) {
                if ( matrix[row][col] == '1' ) {
                    if ( row == 0 || col == 0 )
                        dp[row][col] = 1;
                    else 
                        dp[row][col] = min( dp[row - 1][col], min( dp[row][col - 1], dp[row - 1][col - 1] ) ) + 1;

                    maxSide = max( maxSide, dp[row][col] );
                }
            }
        }

        return maxSide * maxSide;
    }
};

int main()
{
    

    return 0;
}