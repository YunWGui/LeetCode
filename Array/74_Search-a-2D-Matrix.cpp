/*
Title:
    74. Search a 2D Matrix
    74. 搜索二维矩阵
Address: 
    https://leetcode-cn.com/problems/search-a-2d-matrix/
Tips:
    与 LeetCode-240 完全相同
*/

#include <iostream>
#include <vector>
using namespace std;


// 方法一：从「右上方」开始遍历
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.empty() )
            return false;

        int rows = matrix.size(), cols = matrix[0].size();

        for ( int col = cols - 1; col >= 0; --col ) {
            for ( int row = 0; row < rows; ++row ) {
                if ( matrix[row][col] > target )
                    break;
                else if ( matrix[row][col] == target ) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main()
{
    

    return 0;
}
