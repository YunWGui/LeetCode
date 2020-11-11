/*
Title:
    191. Number of 1 Bits
    191. 位1的个数
Description:
    编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数
Address: 
    https://leetcode-cn.com/problems/number-of-1-bits/
*/

#include <iostream>
using namespace std;


// 方法一：位运算
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while ( n > 0 ) {
            if ( n & 1 )
                ++count;
            n >>= 1;
        }

        return count;
    }
};

// 方法二：位运算
class Solution_2 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while ( n ) {
            ++count;
            n = n & ( n - 1 );
        }

        return count;
    }
};


int main()
{
    

    return 0;
}