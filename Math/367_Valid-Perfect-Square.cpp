/*
Title:
    367. Valid Perfect Square
    367. 有效的完全平方数
Description:
    给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则
    返回 False。
Address:
    https://leetcode-cn.com/problems/valid-perfect-square/
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


// 方法一：
class Solution {
public:
    bool isPerfectSquare(int num) {
        if ( num <= 1 )
            return num;

        int root = sqrtRoot( num );  // 平方根
        if ( root * root == num )
            return true;
        else
            return false;
    }

    int sqrtRoot( int num ) {
        double pre;
        double cur = 1;

        while ( true ) {
            pre = cur;
            cur = pre - ( pre - num / pre ) / 2;  // 牛顿法
            if ( abs( cur - pre ) < 0.0001 )
                return (int)cur;
        }
    }
};



int main()
{


    return 0;
}
