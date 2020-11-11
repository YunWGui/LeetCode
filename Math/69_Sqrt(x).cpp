/*
Title:
    69. Sqrt(x)
    69. x 的平方根
Address:
    https://leetcode-cn.com/problems/sqrtx/
*/

#include <iostream>
#include <cmath>
using namespace std;

// 方法一：顺序遍历
/* i^2 <= x < (i+1)^2 ==> i */
class Solution {
public:
    int mySqrt(int x) {
        long long int i = 0;

        for ( i = 0; i < x; ++i ) {
            if ( i * i <= x && x < ( i + 1 ) * ( i + 1 ) )
                break;
        }

        return i;
    }
};

// 方法二：二分查找
class Solution_2 {
public:
    int mySqrt(int x) {
        if ( x <= 1 )
            return x;

        int left = 0, right = x - 1;

        while ( left <= right ) {  // [left, right]
            long long int mid = left + ( ( right - left ) >> 1);
            if ( mid * mid < x)
                left = mid + 1;
            else if ( x < mid * mid )
                right = mid - 1;
            else  // x == mid * mid
                return mid;
        }

        return right;  // right 为 sqrt(x) 的整数部分
    }
};

// 方法三：牛顿法
/*
    令：f(x) = x^2 - a;  即：求出对应的 x
    令 f(x) = 0; f'(x_0) = ( f(x) - f(x_0) ) / ( x - x_0 )
    化简上式有更新公式：x <- ( x + a / x ) / 2
*/
class Solution_3 {
public:
    int mySqrt(int x) {
        if ( x <= 1 )
            return x;

        double pre;
        double cur = 1;
        while ( true ) {
            pre = cur;
            cur = ( cur + x / cur ) / 2;  // 更新公式
            if ( abs( pre - cur ) < 0.0001 )
                return int( cur );
        }
    }
};



int main()
{
    int x;

    printf("Enter x: ");
    scanf("%d", &x);

    Solution solve;

    cout << solve.mySqrt(x) << endl;

    return 0;
}
