/*
Title:
    5627. Stone Game VII
    5627. 石子游戏 VII
Address: 
    https://leetcode-cn.com/contest/weekly-contest-219/problems/stone-game-vii/
    https://leetcode-cn.com/problems/stone-game-vii/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：博弈论、区间 DP
// https://www.acwing.com/activity/content/code/content/637510/
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> nums(n + 1);
        
        for (int i = 1; i <= n; i ++ ) 
            nums[i] = nums[i - 1] + stones[i - 1];
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        for (int len = 2; len <= n; len ++ ) {
            for (int i = 1; i + len - 1 <= n; i ++ ) {
                int j = i + len - 1;
                dp[i][j] = max(nums[j] - nums[i] - dp[i + 1][j], nums[j - 1] - nums[i - 1] - dp[i][j - 1]);
            }
        }
        
        return dp[1][n];
    }
};


int main()
{
    

    return 0;
}