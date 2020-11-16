/*
Title:
    326. Power of Three
    326. 3的幂
Address: 
    https://leetcode-cn.com/problems/power-of-three/
*/

#include <iostream>
#include <vector>
#include <math.h>  // log10, floor
using namespace std;

// 方法三：数学 - 对数法
class Solution_3 {
public:
    bool isPowerOfThree(int n) {
        if ( n <= 0 )
            return false;

        double ans = log10( n ) / log10( 3 );

        return ans == floor( ans );  // floor ：返回不大于 x 的最大整数值（返回值为浮点型）
    }
};

// 方法一：暴力法
class Solution {
public:
    bool isPowerOfThree(int n) {
        long a = 1;

        while ( a < n ) 
            a *= 3;

        return a == n;
    }
};

// 方法二：
class Solution_2 {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;  // 1162261467 为 int 型范围内最大的 3 的幂
    }
};


int main()
{
    

    return 0;
}