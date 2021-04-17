/******************************************************************************
 * Title:
 *     73. Set Matrix Zeroes
 *     73. 矩阵置零
 * Address:
 *     https://leetcode-cn.com/problems/set-matrix-zeroes/
******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // step 1 : 记录所有 0 点的坐标位置
        vector<vector<int>> zero_coordinate;  // 记录 0 的坐标
        for ( int row = 0; row < rows; ++row )
            for ( int col = 0; col < cols; ++col )
                if ( matrix[row][col] == 0 )
                    zero_coordinate.push_back( { row, col } );
        
        // step 2 : 遍历，对每个 0 点坐标的行、列分别进行置零操作
        for ( vector<int>& nums : zero_coordinate ) {
            for ( int r = 0; r < rows; ++r )
                matrix[r][nums[1]] = 0;
            for ( int c = 0; c < cols; ++c )
                matrix[nums[0]][c] = 0;
        }
    }
};



int main()
{
    

    return 0;
}