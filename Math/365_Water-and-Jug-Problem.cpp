/*
Title:
    365. Water and Jug Problem
    365. 水壶问题
Description:
    有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
    如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

    你允许：
        装满任意一个水壶
        清空任意一个水壶
        从一个水壶向另外一个水壶倒水，直到装满或者倒空
Address:
    https://leetcode-cn.com/problems/water-and-jug-problem/
*/

#include <iostream>
#include <algorithm>
using namespace std;

// 方法一：数学
// https://leetcode-cn.com/problems/water-and-jug-problem/solution/shui-hu-wen-ti-by-leetcode-solution/
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if ( x + y < z )
            return false;
            
        if ( x == 0 || y == 0 )
            return z == 0 || x + y == z;
        
        return z % gcd( x, y ) == 0;
    }

    int gcd( int a, int b ) {  // 辗转相除法
        if ( a % b == 0 )
            return b;

        return gcd( b, a % b );
    }
};


// 方法二：
class Solution_2 {
public:
    bool canMeasureWater(int x, int y, int z) {
        int canx = 0, cany = 0;
        
        if (z == 0)
            return true;
        if (x == 0 || y == 0)
            return x + y == z;
        if (x + y == z)
            return true;
        
        while (canx != 0 || cany != y) {
            if (cany == y)
                cany = 0;
            else if (canx == 0)
                canx = x;
            else {
                int diff = y - cany;
                cany = min(y, cany + canx);
                canx = max(0, canx - diff);
            }
            if (canx + cany == z)
                return true;
        }
        
        return false;
    }
};

int main()
{
    

    return 0;
}