/*
Title:
    1690. Stone Game VII
    1690. 石子游戏 VII
Address: 
    https://leetcode-cn.com/contest/weekly-contest-219/problems/stone-game-vii/
    https://leetcode-cn.com/problems/stone-game-vii/
*/

#include <iostream>
#include <vector>
#include <numeric>    // std::accumulate
#include <functional> // std::function
using namespace std;

// 方法二：
// Author: Huahua
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1690-stone-game-vii/
class Solution_2 {
public:
    int stoneGameVII(vector<int> &stones) {
        const int n = stones.size();
        vector<vector<int>> cache(n, vector<int>(n, INT_MAX));
        function<int(int, int, int)> dp = [&](int l, int r, int s) {
            if (l >= r)
                return 0;
            if (cache[l][r] == INT_MAX)
                cache[l][r] = max(s - stones[r] - dp(l, r - 1, s - stones[r]),
                                  s - stones[l] - dp(l + 1, r, s - stones[l]));

            return cache[l][r];
        };

        return dp(0, n - 1, accumulate(begin(stones), end(stones), 0));
    }
};

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