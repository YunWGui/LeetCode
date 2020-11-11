/*
Title:
    300. Longest Increasing Subsequence
    300. 最长上升子序列
Description:
    Given an unsorted array of integers, find the length of longest increasing subsequence.
Address:
    https://leetcode-cn.com/problems/longest-increasing-subsequence/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 方法二：贪心 + 二分查找
/*
时间复杂度：O(n*logn) 空间复杂度：O(n)
思路：要使上升子序列尽可能的长，则需要让序列上升得尽可能慢，因此希望每次在上升子序列最后加上的那个数尽可能小
*/
// https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2/
class Solution_2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;

        for ( int i = 0; i < (int)nums.size(); ++i ) {
            int left = 0, right = dp.size();
            while ( left < right ) {  // 二分查找 ：[left, right)
                int mid = left + ( ( right - left ) >> 1 );

                if ( dp[mid] < nums[i] )
                    left = mid + 1;
                else  // dp[mid] >= nums[i]
                    right = mid;
            }

            if ( right >= (int)dp.size() )
                dp.push_back( nums[i] );
            else
                dp[right] = nums[i];
        }

        return dp.size();
    }
};

// 方法一：动态规划
/* 时间复杂度：O(n^2), 空间复杂度：O(n) */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if ( nums.empty() )
            return 0;

        vector<int> dp( nums.size(), 1 );

        for ( int i = 1; i < (int)nums.size(); ++i )
            for ( int j = 0; j < i; ++j )
                if ( nums[j] < nums[i] )  // 以第 i 个数字结尾的的最长上升子序列的长度
                    // dp[i] = max( dp[i], dp[j] + 1 );
                    if ( dp[i] < dp[j] + 1 )
                        dp[i] = dp[j] + 1;

        return *max_element( dp.begin(), dp.end() );
    }
};

// 方法三：基于「方法一」的改进
class Solution_3 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        vector<int> dp ( nums.size(), 1 );

        for ( int i = 0; i < (int)nums.size(); ++i ) {
            for ( int j = 0; j < i; ++j ) {
                if ( nums[j] < nums[i] )
                    dp[i] = max( dp[i], dp[j] + 1 );
            }
            res = max( res, dp[i] );
        }

        return res;
    }
};

int main()
{


    return 0;
}
