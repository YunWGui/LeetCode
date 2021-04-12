/******************************************************************************
 * Title:
 *     377_Combination-Sum-IV
 *     377. 组合总和 Ⅳ
 * Address:
 *     https://leetcode-cn.com/problems/combination-sum-iv/
******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// 【完全背包】

// 方法一：
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long int> dp( target + 1, 0 );
        dp[0] = 1;

        for ( int i = 0; i <= target; ++i ) {
            for ( int num : nums ) {
                if ( num <= i )
                    dp[i] += dp[i - num];
            }
        }

        return dp[target];
    }
};

int main()
{
    

    return 0;
}