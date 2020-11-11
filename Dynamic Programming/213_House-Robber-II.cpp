/*
Title:
    213. House Robber II
    213. 打家劫舍 II
Address: 
    https://leetcode-cn.com/problems/house-robber-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法二：动态规划
class Solution_2 {
public:
    int rob(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        if ( nums.size() == 1 )
            return nums[0];
        if ( nums.size() == 2 )
            return max( nums[0], nums[1] );
        if ( nums.size() == 3 )
            return max( nums[0], max( nums[1], nums[2] ) );
        
        return max( 
            maxMoney( nums, 0, nums.size() - 1 ),  // 不偷最后一间房
            maxMoney( nums, 1, nums.size() )  // 不偷第一间房
        );
    }

    int maxMoney( vector<int> nums, int left, int right ) {
        nums[left + 1] = max( nums[left], nums[left + 1] );  // 判断是否偷最左侧的房
        int i;
        for ( i = left + 2; i < right; ++i )
            nums[i] = max( nums[i - 1], nums[i] + nums[i - 2] );

        return nums[i - 1];
    }
};


// 方法一：动态规划
/* 思路：拆成两个子问题，分开讨论 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        if ( nums.size() == 1 )
            return nums[0];
        if ( nums.size() == 2 )
            return max( nums[0], nums[1] );
        if ( nums.size() == 3 )
            return max( nums[0], max( nums[1], nums[2] ) );
        
        int maxVal_1 = maxMoney( nums );  // 不偷窃「第一个房间」时能获得的最大收益

        nums.insert( nums.begin(), nums.back() );
        nums.pop_back();

        int maxVal_2 = maxMoney( nums );  // 不偷窃「最后一个」房间时能获得的最大收益

        return max( maxVal_1, maxVal_2 );
    }

    int maxMoney( vector<int> nums ) {
        nums[0] = 0;  // 置 0，表示该房间不偷窃
        for ( int i = 2; i < (int)nums.size(); ++i )
            nums[i] = max( nums[i - 1], nums[i] + nums[i - 2] );

        return nums.back();
    }
};

int main()
{
    

    return 0;
}