/*
Title:
    5610. Sum of Absolute Differences in a Sorted Array
    5610. 有序数组中差绝对值之和
Address: 
    https://leetcode-cn.com/contest/biweekly-contest-41/problems/sum-of-absolute-differences-in-a-sorted-array/
    https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：前缀和
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum( n + 1 );

        for ( int i = 1; i <= n; ++i ) 
            sum[i] = sum[i - 1] + nums[i - 1];
        
        vector<int> res;
        for ( int i = 1; i <= n; ++i ) {
            int leftSum = i * nums[i - 1] - sum[i];
            int rightSum = sum[n] - sum[i] - nums[i - 1] * ( n - i );
            res.push_back( leftSum + rightSum );
        }

        return res;
    }
};

int main()
{
    

    return 0;
}
