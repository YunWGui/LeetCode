/*
Title:
    59. Spiral Matrix II
    59. 螺旋矩阵 II
Address: 
    https://leetcode-cn.com/problems/spiral-matrix-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：直觉法
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int idx = 1;
        int up = 0, down = n -1;
        int left = 0, right = n - 1;
        vector<vector<int>> res( n, vector<int>( n, 0 ) );

        while ( left <= right && up <= down ) {
            // up: left -> right
            for ( int col = left; col <= right; ++col ) 
                res[up][col] = idx++;
            ++up;
            // right: up -> down
            for ( int row = up; row <= down; ++row )
                res[row][right] = idx++;
            --right;
            // down: right -> left
            for ( int col = right; col >= left; --col )
                res[down][col] = idx++;
            --down;
            // left: down -> up
            for ( int row = down; row >= up; --row )
                res[row][left] = idx++;
            ++left;
        }

        return res;
    }
};

// 方法二：
class Solution_2 {
  public:
    vector<vector<int>> generateMatrix(int n) {
        int idx = 1;
        int left = 0, right = n - 1, up = 0, down = n - 1;
        vector<vector<int>> res(n, vector<int>(n, 0));

        while (true) {
            for (int col = left; col <= right; col++) 
                res[up][col] = idx++;

            if (++up > down)  break;

            for (int row = up; row <= down; row++) 
                res[row][right] = idx++;

            if (--right < left)  break;

            for (int col = right; col >= left; col--) 
                res[down][col] = idx++;

            if (--down < up)  break;

            for (int row = down; row >= up; row--) 
                res[row][left] = idx++;

            if (++left > right) break;
        }

        return res;
    }
};

int main()
{
    

    return 0;
}