/*
Title:
    39. Combination Sum
    39. 组合总和
Description:
    给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中
    所有可以使数字和为 target 的组合。
    candidates 中的数字可以无限制重复被选取。
    说明：
        所有数字（包括 target）都是正整数。
        解集不能包含重复的组合。 
Address: 
    https://leetcode-cn.com/problems/combination-sum/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：回溯法
class Solution {
public:
    vector<int> track;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTrack( 0, target, candidates );

        return res;
    }

    void backTrack( int start, int target, vector<int>& candidates ) {
        if ( target == 0 ) {
            res.push_back( track );
            return;
        }

        for ( int i = start; i < (int)candidates.size(); ++i ) {
            if ( target < candidates[i] )  // 剪枝
                continue;
            
            track.push_back( candidates[i] );
            backTrack( i, target - candidates[i], candidates );
            track.pop_back();
        }
    }
};

int main()
{
    

    return 0;
}