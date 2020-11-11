/*
Title:
    53. Maximum Subarray
    53. 最大子序和
Description:
    Given an integer array nums, find the contiguous subarray (containing at least one
    number) which has the largest sum and return its sum.
Address:
    https://leetcode-cn.com/problems/maximum-subarray/
Tips:
    同 剑指 offer - 42 - 连续子数组的最大和
    https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];  // 最大和
        for ( int i = 1; i < (int)nums.size(); ++i ) {
            if ( nums[i-1] > 0 )
                nums[i] += nums[i-1];
            // else  // nums[i-1] <= 0, 此外可省略
            //     nums[i] = nums[i];

            maxSum = max( maxSum, nums[i] );  // 比较每一次更新，取最大值
            // if ( maxSum < nums[i] )
            //     maxSum = nums[i];
        }

        return maxSum;
    }
};

// 方法二：滑动窗口
class Solution_2 {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0];
        int greatestSum = nums[0];

        for ( size_t i = 1; i < nums.size(); ++i ) {
            if ( curSum <= 0 )
                curSum = nums[i];
            else
                curSum += nums[i];

            if ( greatestSum < curSum )  // 比较每一次更新，取最大值
                greatestSum = curSum;
        }

        return greatestSum;
    }
};


int main()
{


    return 0;
}
