/*
Title:
    463. Island Perimeter
    463. 岛屿的周长
Address: 
    https://leetcode-cn.com/problems/island-perimeter/
*/


#include <iostream>
#include <vector>
using namespace std;

// 方法一：
/*
思路：
    对于一个陆地格子的每条边，它被算作岛屿的周长当且仅当这条边为网格的边界或者相邻
    的另一个格子为水域。 
    因此，我们可以遍历每个陆地格子，看其四个方向是否为边界或者水域，如果是，将这条
    边的贡献（即 11）加入答案 \textit{ans}ans 中即可。
*/
class Solution {
  public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int res = 0;
        int rows = grid.size(), cols = grid[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    if (row == 0 || grid[row - 1][col] == 0)
                        ++res;
                    if (col == 0 || grid[row][col - 1] == 0)
                        ++res;
                    if (row == rows - 1 || grid[row + 1][col] == 0)
                        ++res;
                    if (col == cols - 1 || grid[row][col + 1] == 0)
                        ++res;
                }
            }
        }
        
        return res;
    }
};

// 方法二：暴力法
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        const int rows = grid.size();
        const int cols = grid[0].size();

        for ( int row = 0; row < rows; ++row ) {
            for ( int col = 0; col < cols; ++col ) {
                if ( grid[row][col] == 1 )
                    ans += findLand( grid, row, col, rows, cols );
            }
        }

        return ans;
    }

    int findLand( vector<vector<int>>& grid, int row, int col, int rows, int cols ) {
        int count = 4;
        
        if ( row >= 1 && grid[row - 1][col] == 1 )
            --count;
        if ( col >= 1 && grid[row][col - 1] == 1 )
            --count;
        if ( row + 1 < rows && grid[row + 1][col] == 1 )
            --count;
        if ( col + 1 < cols && grid[row][col + 1] == 1 )
            --count;
        
        return count;        
    }
};


int main()
{
    

    return 0;
}