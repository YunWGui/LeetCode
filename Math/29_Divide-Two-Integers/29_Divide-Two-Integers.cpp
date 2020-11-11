/**
 * 题目：
 *      29. Divide Two Integers
 *      29. 两数相除
 * 地址：
 *      https://leetcode-cn.com/problems/divide-two-integers/
 */

#include<iostream>
#include<cmath>
using namespace std;


// 方法一：指数
/*
    log(a) - log(b) = log(a/b)
    a/b = exp(log(a/b))
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negFlag;  // negFlag : 标记是否存在「负数」
        negFlag = ( ( dividend < 0 ) ^ ( divisor < 0 ) ) ? true : false;  // 异或

        double a = dividend;
        double b = divisor;

        if ( a < 0 )  a = abs( a );
        if ( b < 0 )  b = abs( b );

        double val = exp( log( a ) - log( b ) );

        if ( val >= INT_MAX )
            return negFlag ? INT_MIN : INT_MAX;

        return negFlag ? -val : val;
    }
};


// 方法二：
class Solution_2 {
public:
    int divide(int dividend, int divisor){
        if(dividend == 0)  return 0;
        if(dividend == INT_MIN && divisor == -1)  return INT_MAX;
        if(dividend == INT_MIN && divisor == 1)  return INT_MIN;

        int res = 0;
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        long long dvs_bk = dvs;

        while(dvd >= dvs){
            int curr = 1;
            dvs <<= 1;
            while(dvd - dvs >= 0){
                curr *= 2;
                dvs <<= 1;
            }
            dvs >>= 1;
            dvd -= dvs;
            dvs = dvs_bk;
            res += curr;
        }

        if(dividend > 0 && divisor < 0)
            res *= -1;
        else if(dividend < 0 && divisor > 0)
            res *= -1;

        return res;
    }
};


// 方法三：超时
class Solution_3 {
public:
    int divide(int dividend, int divisor) {
        if ( dividend == 0 )  return 0;
        if ( dividend == INT_MIN && divisor == - 1 )  return INT_MAX;
        if ( dividend == INT_MIN && divisor == 1 )  return INT_MIN;

        long long int dvd = abs( dividend );
        long long int dvs = abs( divisor );
        long long int res = 0;

        while ( dvd >= dvs ) {
            dvd -= dvs;
            ++res;
        }

        if ( ( dividend > 0 && divisor > 0 ) || ( dividend < 0 && divisor < 0 ) )
            return res;
        else
            return -res;
    }
};


int main()
{
    Solution s;
    cout << s.divide(10, 3) << endl;
    cout << s.divide(-7, 3) << endl;
    cout << s.divide(-2147483648, -1) << endl;
    cout << s.divide(-2147483647, 2) << endl;


    return 0;
}
