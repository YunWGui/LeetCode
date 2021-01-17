/*******************************************************************************
 * Title:
 *     605. Can Place Flowers
 *     605. 种花问题
 * Address: 
 *     https://leetcode-cn.com/problems/can-place-flowers/
 ******************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

// 方法二：两点式
/*
 *   一般式：Ax+By+C=0（AB≠0）
 *   两点式：(y-y1)/(x-x1)=(y-y2)/(x-x2) 　（直线过定点(x1,y1),(x2,y2)）
 *   这里取定点为coordinates[0],和coordinates[n-1]
 *   为避免除法运算，这里用「两内项的积等于两外项的积」计算
 */
class Solution_2 {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();

        for ( int i = 1; i < n - 1; ++i ) {
            if (  // 当 (y - y1) * ( x - x2 ) == ( x - x1 ) * ( y - y2 )，则在同一直线上 
                ( coordinates[i][1] - coordinates[0][1] ) * ( coordinates[i][0] - coordinates[n - 1][0] ) 
                != ( coordinates[i][0] - coordinates[0][0] ) * ( coordinates[i][1] - coordinates[n - 1][1] )
            ) {
                return false;
            }
        }

        return true;
    }
};


// 方法一：模拟
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        int cnt = 0;
        
        int left = 0;
        while ( left < flowerbed.size() ) {
            cnt = 0;
            if ( flowerbed[left] == 0 ) {
                if ( left == 0 )
                    ++cnt;
                
                ++left;
                while ( left < flowerbed.size() && flowerbed[left] == 0 ) {
                    ++cnt;                   
                    ++left;
                }

                if ( left < flowerbed.size() )  // 即： flowerbed[left] == 1
                    --cnt;
                if ( cnt > 0 )
                    ans += ( cnt - 1 ) / 2 + 1;
            }
            ++left;
        }

        return ans >= n;
    }
};

int main()
{
    

    return 0;
}