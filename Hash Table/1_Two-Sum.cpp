/*
Title:
    1. Two Sum
    1. 两数之和
Description:
    Given an array of integers, return indices of the two numbers such that they 
    add up to a specific target.
    You may assume that each input would have exactly one solution, and you may 
    not use the same element twice.
Example:
    Input: nums = [2, 7, 11, 15], target = 9
    Output: [0, 1]
Address: 
    https://leetcode-cn.com/problems/two-sum/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// 方法二：哈希表
class Solution_2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int, int> hashMap;

        for ( int i = 0; i < (int)nums.size(); ++i )
            hashMap[nums[i]] = i;
        
        // 如果存在「重复」的两个数，则在 hashMap 中保存的是数组「右侧」的那个重复数字
        // 而 for 语句「自左往右」遍历，最先遍历到数组「左侧」的那个重复数字，
        // 故，如果数组存在「重复」的两个数，哈希表也能很好的处理
        for ( int i = 0; i < (int)nums.size(); ++i ) {
            int other = target - nums[i];
            if ( hashMap.find( other ) != hashMap.end() && hashMap[other] != i )
                return { i, hashMap[other] };
        }

        return { -1, -1 };
    }
};


// 方法一：暴力法 - 穷举
/* 时间复杂度：O(n^2)  空间复杂度：O(1) */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if ( nums.empty() )
            return vector<int> {};
        
        int i, j;
        for ( i = 0; i < (int)nums.size() - 1; ++i ) {
            for ( j = i + 1; j < (int)nums.size(); ++j ) {
                if ( nums[i] + nums[j] == target )
                    return { i, j };
            }
        }

        return { i, j };
    }
};


int main()
{
    

    return 0;
}