/*******************************************************************************
 * Title:
 *     628. Maximum Product of Three Numbers
 *     628. 三个数的最大乘积
 * Address: 
 *     https://leetcode-cn.com/problems/maximum-product-of-three-numbers/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort( nums.begin(), nums.end() );

        int ans = 0;
        int n = nums.size();
        
        ans = nums[n - 1] * nums[n - 2] * nums[n - 3];

        if ( nums[1] < 0 )
            ans = max( ans, nums[0] * nums[1] * nums[n - 1] );

        return ans;
    }
};


// 方法二：线性扫描
/**
 * 只需要知道最大的三个数和最小的两个数即可
 */
class Solution_2 {
public:
    int maximumProduct(vector<int>& nums) {
        int first_max = INT_MIN, second_max = INT_MIN, third_max = INT_MIN;  // 最大的三个数
        int first_min = INT_MAX, second_min = INT_MAX;  // 最小的两个数

        for ( int& num : nums ) {
            if ( num > first_max ) {
                third_max = second_max;
                second_max = first_max;
                first_max = num;
            } 
            else if ( num > second_max ) {
                third_max = second_max;
                second_max = num;
            }
            else if ( num > third_max ) {
                third_max = num;
            }

            if ( num < first_min ) {
                second_min = first_min;
                first_min = num;
            }
            else if ( num < second_min ) {
                second_min = num;
            }
        }

        return max ( first_max * second_max * third_max, first_min * second_min * first_max );
    }
};

int main()
{
    

    return 0;
}