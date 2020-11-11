/*
Title:
    198. House Robber
    198. 打家劫舍
Address: 
    https://leetcode-cn.com/problems/house-robber/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：动态规划
class Solution {
public:
    int rob(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        if ( nums.size() == 1 )
            return nums[0];
        
        nums.insert( nums.begin(), 0 );
        for ( int i = 2; i < (int)nums.size(); ++i ) {
            // nums[i - 1] : 不打劫房间 i 的收益；nums[i] + nums[i - 2] : 打劫房间 i 的收益
            // 如果 nums[i - 1] > nums[i] + nums[i - 2]，则不打劫当前屋子，
            // 并将 max( nums[i - 1], nums[i] + nums[i - 2] ) 放入 nums[i] 中
            nums[i] = max( nums[i - 1], nums[i] + nums[i - 2] );  // 更新公式
        }

        return nums.back();
    }
};

// 方法二：基于「方法一」的改进
class Solution_2 {
public:
    int rob(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        if ( nums.size() == 1 )
            return nums[0];
        if ( nums.size() == 2 )
            return max( nums[0], nums[1] );
        
        nums[1] = max( nums[1], nums[0] );
        for ( int i = 2; i < (int)nums.size(); ++i ) {
            nums[i] = max( nums[i - 1], nums[i] + nums[i - 2] );
        }

        return nums.back();
    }
};

int main()
{
    

    return 0;
}