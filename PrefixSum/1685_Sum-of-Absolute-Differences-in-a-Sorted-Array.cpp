/*
Title:
    1685. Sum of Absolute Differences in a Sorted Array
    1685. 有序数组中差绝对值之和
Address: 
    https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：前缀和
/*
题解：
    根据题意，数组 nums 是「非递减」的，因此该数组的「前缀和」要么不变，要么递增
*/
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        const int n = nums.size();
        vector<int> prefixSum( n + 1 );  // 记录数组的前缀和
        
        prefixSum[0] = 0;
        for ( int i = 1; i <= n; ++i ) 
            prefixSum[i] += prefixSum[i - 1] + nums[i - 1];
        
        vector<int> ans;
        for ( int i = 1; i <= n; ++i ) {
            int leftSum = i * nums[i - 1] - prefixSum[i];  // 当前下标「左侧」的结果
            // 当前下标「右侧」的结果
            int rightSum = ( prefixSum[n] - prefixSum[i] ) - ( n - i ) * nums[i - 1];  
            ans.push_back( leftSum + rightSum );
        }

        return ans;        
    }
};

int main()
{
    

    return 0;
}
