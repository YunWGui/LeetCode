/*
Title:
    312. Burst Balloons
    312. 戳气球
Address: 
    https://leetcode-cn.com/problems/burst-balloons/
Classification:
    区间 DP
*/


#include <iostream>
#include <vector>
using namespace std;

// 方法二：动态规划
// 视频：https://www.youtube.com/watch?v=z3hu2Be92UA
class Solution_2 {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert( nums.begin(), 1 );
        nums.push_back( 1 );

        // 区间 DP 
        vector<vector<int>> dp( n + 2, vector<int>( n + 2, 0 ) );
        for ( int gap = 1; gap <= n; ++gap ) {  // 区间「长度」
            for ( int start = 1; start <= n - gap + 1; ++start ) {  // 区间「起点」
                int end = start + gap - 1;  // 区间「终点」
                for ( int k = start; k <= end; ++k ) {
                    dp[start][end] = max( dp[start][end], dp[start][k - 1] + nums[start - 1] * nums[k] * nums[end + 1] + dp[k + 1][end] );
                }
            }
        }

        return dp[1][n];
    }
};

// 方法一：动态规划
// 视频：https://www.bilibili.com/video/BV1U4411E7iZ

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int len = n + 2;
        vector<int> arr ( len );
        arr[0] = 1;
        arr[len - 1] = 1;
        for ( int i = 1; i <= n; ++i )
            arr[i] = nums[i - 1];
        
        // 区间 DP 模板
        vector<vector<int>> dp( len, vector<int>( len ) );
        for ( int gap = 2; gap < len; ++gap ) {  // 区间长度
            for ( int start = 0; start + gap < len; ++start ) {  // 区间起点
                int end = start + gap;  // 区间终点
                int cur = 0;
                for ( int k = start + 1; k < end; ++k ) {
                    cur = max( cur, dp[start][k] + dp[k][end] + arr[start] * arr[k] * arr[end] );
                }
                dp[start][end] = cur;
            }
        }
        
        return dp[0][len - 1];
    }
};

int main()
{
    

    return 0;
}