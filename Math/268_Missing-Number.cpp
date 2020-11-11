/*
Title:
    268. Missing Number
    268. 缺失数字
Address: 
    https://leetcode-cn.com/problems/missing-number/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：数学
/*
    遍历数组，求出数组的总和 sum 
    求 0, 1, 2, ..., n 的总和 ( ( n * ( n + 1 ) )  / 2 )
    ( ( n * ( n + 1 ) )  / 2 ) - sum 即为缺失的数
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long int sum = 0;

        for ( int num : nums )
            sum += num;
        
        return ( n * ( n + 1 ) / 2 ) - sum;
    }
};

int main()
{
    

    return 0;
}