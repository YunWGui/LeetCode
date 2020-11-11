/*
Title:
    372. Super Pow
    372. 超级次方
Address: 
    https://leetcode-cn.com/problems/super-pow/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：递归 + 快速幂
// https://labuladong.gitbook.io/algo/gao-pin-mian-shi-xi-lie/superpower
class Solution {
public:
    const int MOD = 1337;

    int superPow(int a, vector<int>& b) {
        if ( b.empty() )
            return 1;
        
        // 取出最后一个数
        int last = b.back();
        b.pop_back();

        // 将原问题化简，缩小规模
        int part1 = qpow( a, last );
        int part2 = qpow( superPow( a, b ), 10 );  // 递归

        return part1 * part2 % MOD;
    }

    int qpow( long long int a, long long int n ) {
        long long int res = 1;
        while ( n ) {
            if ( n & 1 )
                res = res * a % MOD;
            a = a * a % MOD;
            n >>= 1;
        }

        return res;
    }
};


int main()
{
    

    return 0;
}