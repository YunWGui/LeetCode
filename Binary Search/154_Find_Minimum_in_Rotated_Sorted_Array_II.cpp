/*
Title:
    154. Find Minimum in Rotated Sorted Array II
    154. 寻找旋转排序数组中的最小值 II
Descirption:
    数组中可能存在「重复」元素
Address:
    https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
Tips:
    同 《剑指offer》第11题
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：二分查找
/* 时间复杂度：O(logn)  空间复杂度：O(1) */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while ( left < right ) {
            int mid = left + ( ( right - left ) >> 1 );

            if ( nums[mid] < nums[right] )
                right = mid;
            else if ( nums[mid] == nums[right] )
                --right;
            else // nums[mid] > nums[right]
                left = mid + 1;
        }

        return nums[left];
    }
};


// 方法二：
class Solution_2 {
public:
    int findMin(vector<int>& nums) {
        if ( nums.size() == 1 )
            return nums[0];
            
        int left = 0, right = nums.size() - 1;
        int mid = left;
        while ( nums[left] >= nums[right] ) {
            if ( right - left == 1 ) {
                mid = right;
                break;
            }
            mid = ( left + right )>>1;
            // 如果下标 left, right, mid 指向的三个数字相等
            // 则只能顺序查找
            if ( nums[left] == nums[right] && nums[mid] == nums[left] )
                return minInOrder( nums, left, right );

            if ( nums[mid] >= nums[left] )
                left = mid;
            else if ( nums[mid] <= nums[right] )
                right = mid;
        }
        return nums[mid];
    }

    int minInOrder( vector<int>& nums, int left, int right ) {
        int res = nums[0];
        for ( int i = left + 1; i <= right; ++i ) {
            if ( nums[i] < res ) 
                res = nums[i];
        }
        
        return res;
    }
};

int main()
{
    

    return 0;
}