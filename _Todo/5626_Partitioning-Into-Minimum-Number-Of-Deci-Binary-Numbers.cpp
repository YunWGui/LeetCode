/*
Title:
    5626. Partitioning Into Minimum Number Of Deci-Binary Numbers
    5626. 十-二进制数的最少数目
Address: 
    https://leetcode-cn.com/contest/weekly-contest-219/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 方法一：
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