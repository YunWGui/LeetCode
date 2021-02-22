/*******************************************************************************
 * Title:
 *     657. Robot Return to Origin
 *     657. 机器人能否返回原点
 * Address:
 *     https://leetcode-cn.com/problems/robot-return-to-origin/
 ******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// 方法二：
class Solution_2 {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for ( char ch : moves ) {
            if ( ch == 'R' )       ++x;
            else if ( ch == 'L' )  --x;
            else if ( ch == 'U' )  ++y;
            else if ( ch == 'D' )  --y;
        }

        return ( x == 0 ) && ( y == 0 );
    }
};

// 方法一：
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;  // 原点坐标
        int dx[4] = { 1, -1, 0, 0 };
        int dy[4] = { 0, 0, 1, -1 };
        
        int map[128];
        map['R'] = 0;
        map['L'] = 1;
        map['U'] = 2;
        map['D'] = 3;      

        for ( char ch : moves ) {
            x += dx[map[ch]];
            y += dy[map[ch]];
        }

        return x == 0 && y == 0;
    }
};


int main()
{
    

    return 0;
}