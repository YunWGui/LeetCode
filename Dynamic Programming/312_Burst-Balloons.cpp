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

// 方法三：动态规划
// AcWing : https://www.acwing.com/video/1702/
class Solution_3 {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr( n + 2, 1 );
        for ( int i = 1; i <= n; ++i )  arr[i] = nums[i - 1];  // 前缀和

        vector<vector<int>> dp( n + 2, vector<int>( n + 2, 0 ) );
        for ( int len = 3; len <= n + 2; ++len ) {  // 阶段：len = 3，表示原数组 nums 只有一个元素
            for ( int left = 0; left + len - 1 <= n + 1; ++left ) {  // 状态：左端点
                int right = left + len - 1;  // 状态：右端点
                for ( int k = left + 1; k < right; ++k ) {  // 决策：k 表示被戳的气球，取值为 arr[1 ~ n]
                    dp[left][right] = max( dp[left][right], dp[left][k] + dp[k][right] + arr[left] * arr[k] * arr[right] );
                }
            }
        }

        return dp[0][n + 1];
    }
};


// 方法二：动态规划
// 视频：https://www.youtube.com/watch?v=z3hu2Be92UA
class Solution_2 {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert( nums.begin(), 1 );
        nums.push_back( 1 );

        // 区间 DP 模板
        vector<vector<int>> dp( n + 2, vector<int>( n + 2, 0 ) );
        for ( int len = 1; len <= n; ++len ) {  // 区间「长度」
            for ( int left = 1; left + len - 1 <= n; ++left ) {  // 区间「起点」
                int right = left + len - 1;  // 区间「终点」
                for ( int k = left; k <= right; ++k ) {
                    dp[left][right] = max( dp[left][right], dp[left][k - 1] + nums[left - 1] * nums[k] * nums[right + 1] + dp[k + 1][right] );
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
        vector<int> arr ( n + 2, 1 );
        for ( int i = 1; i <= n; ++i )  arr[i] = nums[i - 1]; 
        
        // 区间 DP 模板
        vector<vector<int>> dp( n + 2, vector<int>( n + 2 ) );
        for ( int len = 2; len < n + 2; ++len ) {  // 区间长度
            for ( int left = 0; left + len < n + 2; ++left ) {  // 区间起点
                int right = left + len;  // 区间终点
                int cur = 0;
                for ( int k = left + 1; k < right; ++k ) {
                    cur = max( cur, dp[left][k] + dp[k][right] + arr[left] * arr[k] * arr[right] );
                }
                dp[left][right] = cur;
            }
        }
        
        return dp[0][n + 1];
    }
};

int main()
{
    

    return 0;
}