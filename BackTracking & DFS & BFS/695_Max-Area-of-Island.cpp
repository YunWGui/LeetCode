/*
Title:
    695. Max Area of Island
    695. 岛屿的最大面积
Address:
    https://leetcode-cn.com/problems/max-area-of-island/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：深度优先搜索、递归
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size(), cols = grid[0].size();

        for ( int i = 0; i < rows; ++i ) 
            for ( int j = 0; j < cols; ++j ) 
                if ( 1 == grid[i][j] ) 
                    // 以此坐标为中心，向四周扩散
                    maxArea = max( maxArea, getArea( grid, i, j, rows, cols ) );

        return maxArea;
    }

    int getArea( vector<vector<int>>& grid, int i, int j, int rows, int cols ) {
        if ( i >= 0 && i < rows && j >= 0 && j < cols && ( 1 == grid[i][j] ) ) {  // 没有越界
            grid[i][j] = 0;  // 置零

            return 1 + getArea( grid, i-1, j, rows, cols ) 
                     + getArea( grid, i+1, j, rows, cols ) 
                     + getArea( grid, i, j-1 , rows, cols ) 
                     + getArea( grid, i, j+1 , rows, cols );
        }

        return 0;  // 坐标越界
    }
};

int main()
{
    

    return 0;
}