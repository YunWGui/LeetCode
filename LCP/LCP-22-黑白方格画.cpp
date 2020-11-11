/*
题目： 
    LCP 22. 黑白方格画
描述：
    小扣注意到秋日市集上有一个创作黑白方格画的摊位。摊主给每个顾客提供一个固定在墙
    上的白色画板，画板不能转动。画板上有 n * n 的网格。
    绘画规则为，小扣可以选择任意多行以及任意多列的格子涂成黑色，所选行数、列数均可为 0。
    小扣希望最终的成品上需要有 k 个黑色格子，请返回小扣共有多少种涂色方案。
    注意：两个方案中任意一个相同位置的格子颜色不同，就视为不同的方案。
地址：
    https://leetcode-cn.com/problems/ccw6C7/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int paintingPlan(int n, int k) {
        if ( n * n == k )
            return 1;
        
        int ans = 0;

        for ( int row = 0; row <= n; ++row ) {
            for ( int col = 0; col <= n; ++col ) {
                if ( ( row + col ) * n - row * col == k ) {  // 核心公式
                    ans += combination( n, row ) * combination( n, col );
                }
            }
        }

        return ans;
    }

    int combination( int n, int row ) {
        int ans = 1;

        for ( int i = row + 1; i <= n; ++i )
            ans = ans * i;
        
        for ( int i = 1; i <= n - row; ++i )
            ans = ans / i;     

        return ans;
    }

};

int main()
{
    

    return 0;
}