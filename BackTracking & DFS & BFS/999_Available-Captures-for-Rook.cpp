/*
Title:
    999. Available Captures for Rook
    999. 可以被一步捕获的棋子数
Address:
    https://leetcode-cn.com/problems/available-captures-for-rook/
*/

#include <iostream>
#include <vector>
using namespace std;


// 方法二：DFS
class Solution_2 {
private:
    int count = 0;

public:

    int numRookCaptures(vector<vector<char>>& board) {
        for ( int i = 0; i < 8; ++i ) {
            for ( int j = 0; j < 8; ++j ) {
                if ( board[i][j] == 'R' ) {
                    dfs( i + 1, j, 1, 0, board );
                    dfs( i, j - 1, 0, -1, board );
                    dfs( i - 1, j, -1, 0, board );
                    dfs( i, j + 1, 0, 1, board );
                }
            }
        }

        return count;
    }   

    void dfs( int i, int j, int dx, int dy, vector<vector<char>>& board ) {
        if ( i < 0 || i >= 8 || j < 0 || j >= 8 || board[i][j] == 'B' )
            return;
        if ( board[i][j] == 'p' ) {
            ++count;
            return;
        }

        dfs( i + dx, j + dy, dx, dy, board );
    }
};

// 方法一：模拟法
// https://leetcode-cn.com/problems/available-captures-for-rook/solution/che-de-ke-yong-bu-huo-liang-by-leetcode-solution/
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0, st = 0, ed = 0;
        // dx, dy 为方向数组
        int dx[4] = { 1, 0, -1, 0 };  
        int dy[4] = { 0, -1, 0, 1 };

        for ( int i = 0; i < 8; ++i ) {
            for ( int j = 0; j < 8; ++j ) {
                if ( board[i][j] == 'R' ) {
                    st = i;
                    ed = j;
                    break;
                }
            }
        }

        for ( int i = 0; i < 4; ++i ) {
            for ( int step = 0; ; ++step ) {
                int tx = st + step * dx[i];
                int ty = ed + step * dy[i];

                if ( tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B' )
                    break;
                
                if ( board[tx][ty] == 'p' ) {
                    ++count;
                    break;
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