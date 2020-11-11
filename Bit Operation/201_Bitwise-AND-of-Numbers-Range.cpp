/*
Title:
    201. Bitwise AND of Numbers Range
    201. 数字范围按位与
Address: 
    https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：移位
// https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/solution/shu-zi-fan-wei-an-wei-yu-by-leetcode-solution/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while ( m < n ) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        
        return m <<= shift;
    }
};

int main()
{
    

    return 0;
}