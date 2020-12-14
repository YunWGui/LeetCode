/*
Title:
    1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
    1689. 十-二进制数的最少数目
Address: 
    https://leetcode-cn.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 方法一：
/*
    思路：由于不含任何「前导零」，故「十-二进制数」的数目由 n 中最大的一位决定
*/
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        
        for ( char ch : n ) {
            ans = max( ans, ch - '0' );
        }
        
        return ans;
    }
};

int main()
{
    

    return 0;
}