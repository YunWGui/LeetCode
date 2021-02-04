/*******************************************************************************
 * Title:
 *     643. Maximum Average Subarray I
 *     643. 子数组最大平均数 I
 * Address: 
 *     https://leetcode-cn.com/problems/maximum-average-subarray-i/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>  // accumulate
#include <climits>  // INT_MIN
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;

        if ( k >= n ) {
            ans = accumulate( nums.begin(), nums.end(), 0 );
            return 1.0 * ans / n;
        }

        int curSum = 0;
        for ( int i = 0; i < k; ++i ) {
            curSum += nums[i];
        }

        ans = curSum;  // ans = max( ans, curSum );

        for ( int i = k; i < n; ++i ) {
            curSum = curSum - nums[i - k] + nums[i];
            ans = max( ans, curSum );                       
        }

        return 1.0 * ans / k;
    }
};

int main()
{
    

    return 0;
}