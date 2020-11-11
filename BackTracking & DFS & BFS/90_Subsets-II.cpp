/*
Title:
    90. Subsets II
    90. 子集 II
Description:
    给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

    说明：解集不能包含重复的子集。
Address: 
    https://leetcode-cn.com/problems/subsets-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法二：回溯
class Solution_2 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        vector<int> track;
        vector<vector<int>> res;

        backTrack( res, nums, track, 0 );

        return res;
    }

    void backTrack( vector<vector<int>>& res, vector<int>& nums, vector<int>& track, int start ) {      
        res.push_back( track );

        for ( int i = start; i < (int)nums.size(); ++i ) {
            if ( start < i && nums[i] == nums[i - 1] )  // 去重
                continue;
                
            track.push_back( nums[i] );
            backTrack( res, nums, track, i + 1 );
            track.pop_back();
        }
    }
};

// 方法一：回溯
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        vector<int> track;
        vector<vector<int>> res;

        backTrack( res, nums, track, 0 );

        return res;
    }

    void backTrack( vector<vector<int>>& res, vector<int>& nums, vector<int>& track, int start ) {      
        if ( find( res.begin(), res.end(), track) != res.end() )
            return;

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