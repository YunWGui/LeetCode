/*
Title:
    34. Find First and Last Position of Element in Sorted Array
    34. 在排序数组中查找元素的第一个和最后一个位置
Description:
    Given an array of integers nums sorted in ascending order, find the starting
    and ending position of a given target value.
    Your algorithm's runtime complexity must be in the order of O(log n).
    If the target is not found in the array, return [-1, -1].

    Example 1:
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

    Example 2:
    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
Address:
    https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/


#include <iostream>
#include <vector>
#include <algorithm>  // lower_bound, upper_bound
using namespace std;


// 方法三：二分查找
class Solution {
public:
    int binarySearch(vector<int> &nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() &&
            nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1, -1};
    }
};

// 方法一：STL 算法
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        
        if (left == right)  
            return vector<int>{-1, -1};
        else    
            return vector<int>{(int)(left - nums.begin()), (int)(right - nums.begin() - 1)};
    }
};

// 方法二：暴力法 - 顺序遍历 
class Solution_2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        vector<int> res;

        for ( int i = 0; i < nums.size(); ++i ) {
            if ( start == -1 && nums[i] == target )
                start = i;
            if ( nums[i] == target )
                end = i;
        }
        res.emplace_back( start );
        res.emplace_back( end );

        return res;
    }
};


int main()
{


    return 0;
}
