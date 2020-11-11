/*
Title:
    40. Combination Sum II
    40. 组合总和 II
Description:
    给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字
    和为 target 的组合。
    candidates 中的每个数字在每个组合中只能使用一次。
    说明：
        所有数字（包括目标数）都是正整数。
        解集不能包含重复的组合。 
Address: 
    https://leetcode-cn.com/problems/combination-sum-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：回溯法
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> track;
        vector<vector<int>> res;

        sort( candidates.begin(), candidates.end() );

        backTrack( 0, target, candidates, track, res );

        return res;
    }

    void backTrack( int start, int target, vector<int>& candidates, vector<int>& track, vector<vector<int>>& res ) {
        if ( target == 0 ) {
            res.push_back( track );
            return;
        }

        for ( int i = start; i < (int)candidates.size(); ++i ) {
            if ( target < candidates[i] )  // 剪枝
                continue;
            if ( start < i && candidates[i - 1] == candidates[i] )  // 去重
                continue;
            
            track.push_back( candidates[i] );
            backTrack( i + 1, target - candidates[i], candidates, track, res );
            track.pop_back();
        }
    }
};

int main()
{
    

    return 0;
}