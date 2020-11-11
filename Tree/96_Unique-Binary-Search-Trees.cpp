/*
Title:
   96. Unique Binary Search Trees
   95. 不同的二叉搜索树
Address:
   https://leetcode-cn.com/problems/unique-binary-search-trees/
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 方法一：卡特兰数
class Solution {
public:
    int numTrees(int n) {
        long long res = 1;
        for ( int i = 0; i < n; ++i ) {
            res = res * 2 * ( 2 * i + 1 ) / ( i + 2 );
        }

        return res;
    }
};

// 方法二：动态规划
// https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode-solution/
/*
    dp[n] = \sum_{i = 1}^{n} dp[i - 1] * dp[n - i]
*/
class Solution_2 {
public:
    int numTrees( int n ) {
        vector<int> dp( n + 1, 0 );
        dp[0] = 1;  // 边界情况，空树
        dp[1] = 1;  // 边界情况，只有根节点
        
        for ( int i = 2; i <= n; ++i ) {
            for ( int j = 1; j <= i; ++j ) 
                dp[i] += dp[j - 1] * dp[i - j];
        }
        
        return dp[n];
    }
};

int main()
{
   

   return 0;
}