/*
Title:
    276. Paint Fence
    276. 栅栏涂色
Description:
    有 k 种颜色的涂料和一个包含 n 个栅栏柱的栅栏，每个栅栏柱可以用其中一种颜色进行上色。

    你需要给所有栅栏柱上色，并且保证其中相邻的栅栏柱 最多连续两个 颜色相同。然后，
    返回所有有效涂色的方案数。

    注意:
    n 和 k 均为非负的整数。

    示例:
    输入: n = 3，k = 2
    输出: 6
    解析: 用 c1 表示颜色 1，c2 表示颜色 2，所有可能的涂色方案有:

                柱 1    柱 2   柱 3     
    -----      -----  -----  -----       
       1         c1     c1     c2 
       2         c1     c2     c1 
       3         c1     c2     c2 
       4         c2     c1     c1  
       5         c2     c1     c2
       6         c2     c2     c1
Address: 
    [Locked] https://leetcode-cn.com/problems/paint-fence/

Solution:
    经典的动态规划问题

    定义 f[n] 表示 n 个栅栏时的总方案数。

    1、当 n 为 1 时，上色方案数为 f[1] = k；

    2、当 n 为 2 时，第 2 个栅栏的颜色可以和第 1 个一样，也可以不一样，因此总共有 f[2] = f[1] ×
    k = k × k 个方案数；

    3、当 n > 3 时，给第 n 个栅栏上色时，有两种选择：

        3.1 和上一个不同颜色，那么此时第 n 个可以选的颜色有 k-1 个，截至到 n-1 的
            方案数为 f[n-1]，于是此时的方案总数为：f[n-1] × (k-1)

        3.2 和上一个相同颜色，那么上一个就不能和上上一个同色，第 n 个可以选的颜色
            有 k-1 个，第 n-1 个可以选的颜色只有一个，那就是和第 n 个一样的那个，
            因此截至 n-1 的方案数为 f[n-2] × 1，于是此时的方案总数为：f[n-2] × 1 × (k-1)；

        3.3 合计两个情况，给 n 个栅栏上色总共有 f[n] = f[n - 1] × (k - 1) + f[n - 2] × (k - 1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if ( n == 0 )
            return 0;
        if ( n == 1 )
            return k;

        int dp[n + 1];
        dp[1] = k;
        dp[2] = k * k;

        for ( int i = 3; i <= n; ++i ) {
            // dp[i] = ( k - 1 ) * ( dp[i - 1] + dp[i - 2] );
            dp[i] = dp[i - 1] * ( k - 1 ) + dp[i - 2] * ( k - 1 );
        }

        return dp[n];
    }
};

int main()
{
    

    return 0;
}