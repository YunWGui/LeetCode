/*
Title:
    172. Factorial Trailing Zeroes
    172. 阶乘后的零
Address: 
    https://leetcode-cn.com/problems/factorial-trailing-zeroes/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
// https://leetcode-cn.com/problems/factorial-trailing-zeroes/solution/xiang-xi-tong-su-de-si-lu-fen-xi-by-windliang-3/
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while ( n > 0 ) {
            n /= 5;
            count += n;
            // count += n / 5;
            // n /= 5;
        }

        return count;
    }
};

int main()
{
    

    return 0;
}