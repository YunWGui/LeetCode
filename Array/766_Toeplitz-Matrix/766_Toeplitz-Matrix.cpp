/*
Title:
    766. Toeplitz Matrix
    766. 托普利茨矩阵
Address: 
    https://leetcode-cn.com/problems/toeplitz-matrix/
*/


#include <iostream>
#include <vector>
using namespace std;


// 方法二：
class Solution_2 {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        for ( int row = 1; row < rows; ++row ) {
            for ( int col = 1; col < cols; ++col )
                if ( matrix[row][col] != matrix[row - 1][col - 1] )
                    return false;
        }

        return true;
    }
};

// 方法一：
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if ( matrix.empty() || matrix.size() == 1 || matrix[0].size() == 1 )
            return true;

        int rowEnd = matrix.size() - 1, colEnd = matrix[0].size() - 1;  // 行、列边界

        // 行
        for ( int start = 0; start < rowEnd; ++start ) {
            int i = start, j = 0;
            int val = matrix[i][j];
            ++i; ++j;
            while ( i <= rowEnd && j <= colEnd ) {
                if ( val != matrix[i][j] )
                    return false;
                ++i; ++j;
            }
        }

        // 列
        for ( int start = 1; start < colEnd; ++start ) {
            int i = 0, j = start;
            int val = matrix[i][j];
            ++i; ++j;
            while ( i <= rowEnd && j <= colEnd ) {
                if ( val != matrix[i][j] )
                    return false;
                ++i; ++j;
            }
        }

        return true;
    }
};


// 方法一的改写
class Solution_1 {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        for ( int col = 0; col < cols; ++col ) {
            int row = 0;
            for ( int r = row + 1, c = col + 1; r < rows && c < cols; ++r, ++c ) {
                if ( matrix[row][col] != matrix[r][c] )
                    return false;
            }
        }

        for ( int row = 1; row < rows; ++row ) {
            int col = 0;
            for ( int r = row + 1, c = col + 1; r < rows && c < cols; ++r, ++c ) {
                if ( matrix[row][col] != matrix[r][c] )
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    

    return 0;
}