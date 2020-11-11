/*
Title:
    1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
    1477. 找两个和为目标值且不重叠的子数组
Address: 
    https://leetcode-cn.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// https://blog.csdn.net/qq_33287871/article/details/106983452
// 方法一：动态规划 + 哈希表
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int res = n + 1;
        vector<int> dp( n, n + 1 );  // 前 i 个元素中存在的连续子数组和为 target 的最小长度
        unordered_map<int, int> M;  // 查询以 i 结尾，且和为 target 的连续子数组是否存在
        int sum = 0;

        M[0] = -1;
        for ( int i = 0; i < n; ++i ) {
            sum += arr[i];
            M[sum] = i;
            
            if ( i > 0 )
                dp[i] = dp[i - 1];
            
            if ( M.count( sum - target ) ) {
                int prev = M[sum - target];  // 查询该连续子数组的最左的起点位置索引
                if ( prev >= 0 && dp[prev] <= n ) 
                    res = min( ( i - prev ) + dp[prev], res );
                dp[i] = min( dp[i], i - prev );
            }
        }

        return res > n ? -1 : res;
    }
};

int main()
{
    

    return 0;
}