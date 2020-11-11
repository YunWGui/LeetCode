/*
Title:
    78. Subsets
    78. 子集
Description:
    给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
    说明：解集不能包含重复的子集。
Address: 
    https://leetcode-cn.com/problems/subsets/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：backTracking - 回溯法
// https://mp.weixin.qq.com/s/qT6WgR6Qwn7ayZkI3AineA
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;

        backTrack( res, nums, track, 0 );

        return res;
    }

    void backTrack( vector<vector<int>>& res, vector<int>& nums, vector<int>& track, int start ) {
        res.push_back( track );

        for ( int i = start; i < (int)nums.size(); ++i ) {
            track.push_back( nums[i] );
            backTrack( res, nums, track, i + 1 );
            track.pop_back();
        }
    }
};


int main()
{
    

    return 0;
}