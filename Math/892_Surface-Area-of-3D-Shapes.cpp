/*
Title:
    892. Surface Area of 3D Shapes
    892. 三维形体的表面积
Address:
    https://leetcode-cn.com/problems/surface-area-of-3d-shapes/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode-cn.com/problems/surface-area-of-3d-shapes/solution/shi-li-you-tu-you-zhen-xiang-jiang-jie-yi-kan-jiu-/
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int count = 0;
        int rows, cols;
        rows = cols = grid.size();

        for ( int i = 0; i < rows; ++i ) {
            for ( int j = 0; j < cols; ++j ) {
                int level = grid[i][j];
                if ( level > 0 ) {
                    // 一个柱体中，2 个底面 + 所有的正文休都贡献了 4 个侧表面积
                    count += (level<<2) + 2;
                // 两个柱体相贴的表面积：两个柱体高的最小值 * 2
                // 减掉 i 与 i - 1 相贴的两份表面积
                if ( i > 0 )
                    count -= min( level, grid[i-1][j] )<<1;
                // 减掉 j 与 j - 1 相贴的两份表面积
                if ( j > 0 )
                    count -= min( level, grid[i][j-1] )<<1;
                }
            }
        }    
        
        return count;
    }
};

int main()
{
    

    return 0;
}