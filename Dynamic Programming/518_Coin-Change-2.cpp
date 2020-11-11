/*
Title:
    518. Coin Change 2
    518. 零钱兑换 II
Description:
    You are given coins of different denominations and a total amount of money. 
    Write a function to compute the number of combinations that make up that amount. 
    You may assume that you have infinite number of each kind of coin.
Address:
    https://leetcode-cn.com/problems/coin-change-2/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：动态规划 - 一维数组
class Solution_2 {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp( amount + 1, 0 );
        dp[0] = 1;
        for ( int coin : coins ) {
            for ( int i = coin; i <= amount; ++i ) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};


// 方法一: 动态规划 - 二维数组
// https://mp.weixin.qq.com/s/zGJZpsGVMlk-Vc2PEY4RPw
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp( n + 1, vector<int>( amount + 1, 0 ) );
        // base case
        for ( int i = 0; i <= n; ++i ) {
            dp[i][0] = 1;
        }
        for ( int i = 1; i <= n; ++i ) {
            for ( int j = 1; j <= amount; ++j ) {
                if ( j - coins[i - 1] >= 0 )
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][amount];
    }
};

int main()
{


    return 0;
}
