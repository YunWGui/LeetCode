/*
Title:
    1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
    1546. 和为目标值的最大数目不重叠非空子数组数目
Description:
    给你一个数组 nums 和一个整数 target 。
    请你返回 非空不重叠 子数组的最大数目，且每个子数组中数字和都为 target 。
Address:
    https://leetcode-cn.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 方法一：动态规划
// https://mp.weixin.qq.com/s/AJPpAVxlZs3zbwHGn_Tvqw
class Solution {
public:
    int dp[100001] ;  // 第 i 个数字中，满足要求的子数组个数
    unordered_map<int, int> pos_dict;  // key: 前缀和, value: 最大的位置
    int maxNonOverlapping(vector<int>& nums, int target) {
        dp[0] = 0;
        pos_dict[0] = 0;
        for ( int i = 1, sum = 0; i <= (int)nums.size(); ++i ) {
            sum += nums[i - 1];

            // 寻找「前缀和」为 sum - target 的位置
            auto iter = pos_dict.find( sum - target );
            if ( iter != pos_dict.end() )  // 找到了，选择一种更优的策略
                dp[i] = max( dp[i - 1], dp[iter->second] + 1 );
            else  // 没找到，则只有一种策略
                dp[i] = dp[i - 1];

            // 更新 pos_dict 的 value
            pos_dict[sum] = i;
        }

        return dp[nums.size()];
    }
};


int main()
{


    return 0;
}
