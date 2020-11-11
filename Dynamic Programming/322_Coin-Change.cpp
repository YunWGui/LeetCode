/*
Title:
    322. Coin Change
    322. 零钱兑换
Description:
    给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
    如果没有任何一种硬币组合能组成总金额，返回 -1。
    说明：
        你可以认为每种硬币的数量是无限的。
    测试用例：
        输入: coins = [1, 2, 5], amount = 11
        输出: 3
        解释: 11 = 5 + 5 + 1
Address:
    https://leetcode-cn.com/problems/coin-change/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法三：动态规划 - 自上而下
// https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/



// 方法一：动态规划 - 自下而上
// https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 极端情况下, 最多需要 amount 个硬币，即：amount 个 1 元硬币
        // 申请一个长度为 amount + 1 的数组，其元素填充为 amount + 1
        // 此时, dp[amount + 1] == amount + 1, 即: 没有任何一种硬币组合能组成总金额
        vector<int> dp( amount + 1, amount + 1 );

        dp[0] = 0;  // 置零
        for ( int i = 1; i <= amount; ++i ) {
            for ( int j = 0; j < (int)coins.size(); ++j ) {
                if ( coins[j] <= i ) {
                    // 初始时, dp[i] == amount + 1, 表示最坏情况
                    dp[i] = min( dp[i], dp[i - coins[j]] + 1 );
                }
            }
        }

        return ( dp[amount] == amount + 1 ) ? -1 : dp[amount];
    }
};


// 方法二：贪心 + DFS剪枝
// https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/
class Solution_2 {
public:
    int coinChange(vector<int>& coins, int amount){
        if (amount == 0)
            return 0;

        sort(coins.rbegin(), coins.rend());  // 降序排列

        int ans = INT_MAX;
        dfs(coins, amount, 0, 0, ans);

        return ans == INT_MAX ? -1 : ans;
    }

    void dfs(vector<int>& coins, int amount, int c_index, int count, int& ans){
        if (amount == 0) {
            ans = min(ans, count);
            return;
        }
        if (c_index == (int)coins.size())
            return;

        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
            dfs(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
    }
};

int main()
{


    return 0;
}
