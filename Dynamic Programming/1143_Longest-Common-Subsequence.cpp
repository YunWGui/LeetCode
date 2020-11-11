/*
Title:
    1143. Longest Common Subsequence
    1143. 最长公共子序列
Address:
    https://leetcode-cn.com/problems/longest-common-subsequence/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法二：动态规划
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if ( text1.empty() || text2.empty() )
            return 0;
        
        int rows = text1.size(), cols = text2.size();
        vector<vector<int>> dp( rows, vector<int>( cols, 0 ) );

        dp[0][0] = ( text1[0] == text2[0] ) ? 1 : 0;
        for ( int row = 1; row < rows; ++row ) {
            if ( dp[row - 1][0] == 1 )
                dp[row][0] = 1;
            else
                dp[row][0] = text1[row] == text2[0] ? 1 : 0;
        }
        for ( int col = 1; col < cols; ++col ) {
            if ( dp[0][col - 1] == 1 )
                dp[0][col] = 1;
            else 
                dp[0][col] = text1[0] == text2[col] ? 1 : 0;
        }

        for ( int row = 1; row < rows; ++row ) {
            for ( int col = 1; col < cols; ++col ) {
                if ( text1[row] == text2[col] )
                    dp[row][col] = max( dp[row - 1][col - 1] + 1, max( dp[row - 1][col], dp[row][col - 1] ) );
                else 
                    dp[row][col] = max( dp[row - 1][col], dp[row][col - 1] );
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

int main()
{
    

    return 0;
}
