/*
Title:
    491. Increasing Subsequences
    491. 递增子序列
Description:
    给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
Address: 
    https://leetcode-cn.com/problems/increasing-subsequences/
*/


#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 方法二：
class Solution_2 {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {      
        set<vector<int>> record;
        vector<int> curRecord;

        dfs( nums, curRecord, record, 0, nums.size() );

        vector<vector<int>> ans( record.begin(), record.end() );

        return ans;
    }

    void dfs( vector<int>& nums, vector<int>& curRecord, set<vector<int>>& record, int start, int end ) {
        if ( start > end )  // 不能取「等号」
            return;
        
        if ( 2 <= curRecord.size() )
            record.insert( curRecord );
        
        for ( int i = start; i < end; ++i ) {
            if ( !curRecord.empty() && nums[i] < curRecord.back() )
                continue;
            
            curRecord.push_back( nums[i] );

            dfs( nums, curRecord, record, i + 1, end );

            curRecord.pop_back();
        }
    }
};

// 方法一：dfs
class Solution {
public:
    vector<int> temp; 
    vector<vector<int>> ans;

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, INT_MIN, nums);
        
        return ans;
    }
    
    void dfs(int cur, int last, vector<int>& nums) {
        if (cur == nums.size()) {
            if (temp.size() >= 2) {
                ans.push_back(temp);
            }
            return;
        }

        if (nums[cur] >= last) {
            temp.push_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            temp.pop_back();
        }

        if (nums[cur] != last) {
            dfs(cur + 1, last, nums);
        }
    }
};


int main()
{
    

    return 0;
}