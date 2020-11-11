/*
Title:
    1547. Minimum Cost to Cut a Stick
    1547. 切棍子的最小成本
Address:
    https://leetcode-cn.com/problems/minimum-cost-to-cut-a-stick/
Tips:
    Weekly Contest 201
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

// 方法一：动态规划 + 深度优先搜索
// https://mp.weixin.qq.com/s/AJPpAVxlZs3zbwHGn_Tvqw
class Solution {
public:
    // dp[left][right] 代表以 cuts[left], cuts[right] 为左右端点的木棍的最小成本
    int dp[103][103];

    int minCost(int n, vector<int>& cuts) {
        memset( dp, -1, sizeof(dp) );
        cuts.push_back( 0 );  // 向 cuts 中加入 0 和 n
        cuts.push_back( n );  // 不会影响答案。因为不会从这两处切割
        sort( cuts.begin(), cuts.end() );

        return dfs( 0, cuts.size() - 1, n, cuts );
    }

    int dfs( int left, int right, int n, vector<int>& cuts ) {
        // 保存已经计算过的答案，避免子问题的重复计算
        if ( dp[left][right] != -1 )
            return dp[left][right];

        // left + 1 == right 时，说明不用再切了
        if ( left + 1 == right ) {
            dp[left][right] = 0;
            return 0;
        }

        // 枚举切割的地方，记录最优解
        for ( int i = left + 1; i < right; ++i ) {
            int cost = dfs( left, i, n, cuts ) + dfs( i, right, n, cuts ) + cuts[right] - cuts[left];
            if ( dp[left][right] == -1 || dp[left][right] > cost )
                dp[left][right] = cost;
        }

        return dp[left][right];
    }
};

int main()
{


    return 0;
}
