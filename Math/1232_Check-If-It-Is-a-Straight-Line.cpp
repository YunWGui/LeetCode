/*******************************************************************************
 * Title:
 *     1232. Check If It Is a Straight Line
 *     1232. 缀点成线
 * Address: 
 *     https://leetcode-cn.com/problems/check-if-it-is-a-straight-line/
 ******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


// 方法一：模拟

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int x = 1, y = 1;  // 是否是沿 x 轴，y 轴方向的直线

        for ( int i = 1; i < n; ++i ) {
            if ( coordinates[i - 1][0] != coordinates[i][0] ) {
                x = 0;
            }
            
            if ( coordinates[i - 1][1] != coordinates[i][1] ) {
                y = 0;
            }

            if ( x == 0 && y == 0 ) {
                break;
            }
        }

        if ( x == 1 || y == 1 ) {
            return true;
        }

        if ( coordinates[1][0] - coordinates[0][0] == 0 ) {
            return false;
        }

        double ratio = 0;  // 斜率
        ratio = (double)( coordinates[1][1] - coordinates[0][1] ) / ( coordinates[1][0] - coordinates[0][0] );

        for ( int i = 2; i < n; ++i ) {
            if ( coordinates[i][0] - coordinates[i - 1][0] == 0 ) {
                return false;
            }

            double k = (double)( coordinates[i][1] - coordinates[i - 1][1] ) / ( coordinates[i][0] - coordinates[i - 1][0] );

            if ( abs( ratio - k ) > 0.00001 ) {
                return false;
            }
        }

        return true;       
    }
};

int main()
{
    vector<vector<int>> arr {{-4,-3},{1,0},{3,-1},{0,-1},{-5,2}};

    Solution solve;
    cout << solve.checkStraightLine( arr );

    return 0;
}