/*
Title:
    77. Combinations
    77. 组合
Description:
    Given two integers n and k, return all possible combinations of k numbers 
    out of 1 ... n.
    You may return the answer in any order.
Address: 
    https://leetcode-cn.com/problems/combinations/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：回溯法
// https://mp.weixin.qq.com/s/qT6WgR6Qwn7ayZkI3AineA
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;

        if ( n <= 0 || k <= 0 )
            return res;
        
        vector<int> track;
        
        backTrack( res, n, k, 1, track );

        return res;
    }

    void backTrack( vector<vector<int>>& res, int n, int k, int start, vector<int>& track ) {
        if ( track.size() == k ) {  // 到达树底部
            res.push_back( track );
            return;
        }

        for ( int i = start; i <= n; ++i ) {
            track.push_back( i );  // 做选择
            backTrack( res, n, k, i + 1, track );
            track.pop_back();  // 撤销选择
        }
    }
};

int main()
{
    

    return 0;
}