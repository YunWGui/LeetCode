/*
Title:
    164. Maximum Gap
    164. 最大间距
Address: 
    https://leetcode-cn.com/problems/maximum-gap/
*/


#include <iostream>
#include <vector>
#include <algorithm>  // max
using namespace std;

// 方法二：桶排序 / 基数排序

// 方法一：暴力法
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if ( nums.size() < 2 )
            return 0;
        
        sort( nums.begin(), nums.end() );
        int maxVal = INT_MIN;
        for ( int i = 1; i < (int)nums.size(); ++i ) {
            maxVal = max( maxVal, nums[i] - nums[i - 1] );
        }

        return maxVal;
    }
};


int main()
{
    

    return 0;
}