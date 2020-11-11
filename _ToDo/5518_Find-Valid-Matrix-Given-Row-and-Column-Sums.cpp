/*
Title:
    5518. Find Valid Matrix Given Row and Column Sums
    5518. 给定行和列的和求可行矩阵
Address: 
    https://leetcode-cn.com/problems/find-valid-matrix-given-row-and-column-sums/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：贪心
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int rows = rowSum.size();
        const int cols = colSum.size();

        vector<vector<int>> matrix ( rows, vector<int>( cols, 0 ) );

        for ( int row = 0; row < rows; ++row ) {
            for ( int col = 0; col < cols; ++col ) {
                matrix[row][col] = min( rowSum[row], colSum[col] );
                rowSum[row] -= matrix[row][col];
                colSum[col] -= matrix[row][col];
            }
        }
        
        return matrix;
    }
};

int main()
{
    

    return 0;
}