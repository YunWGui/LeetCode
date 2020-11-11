/*
Title:
    153. Find Minimum in Rotated Sorted Array
    153. 寻找旋转排序数组中的最小值
Description:
    数组中不存在重复数组
Address:
    https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：二分查找
class Solution {
public:
    int findMin(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        
        int left = 0, right = nums.size() - 1;
        while ( left < right ) {  // [left, right]
            int mid = left + ( ( right - left ) >> 1 );

            if ( nums[mid] <= nums[right] )
                right = mid;
            else  // nums[mid] > nums[right]
                left = mid + 1;
        }

        return nums[left];        
    }
};

int main()
{
    

    return 0;
}