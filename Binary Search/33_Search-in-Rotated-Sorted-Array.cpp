/*
Title:
    33. Search in Rotated Sorted Array
    33. 搜索旋转排序数组
Address:
    https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
*/


#include<iostream>
#include<vector>
using namespace std;


// 方法一：直觉法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if ( nums.empty() )
            return -1;

        int low = 0, high = nums.size()-1;  // 左闭右闭区间 [low, high]
        
        if ( nums.back() < nums[0] ) {  // 如果数组「翻转」
            while ( low < high ) {  // 则找出最小值所在索引
                int mid = low + ( (high-low)>>1 );
                if ( nums[mid] < nums[high] )
                    high = mid;
                else
                    low = mid + 1;
            }
            
            // 划分区间
            if ( nums[0] <= target ) {
                high = low - 1;
                low = 0;
            }
            else {
                low = low;
                high = nums.size()-1;
            }
        }

        while ( low <= high ) {
            int mid = low + ( (high-low)>>1 );
            if ( nums[mid] < target )
                low = mid + 1;
            else if ( target < nums[mid] )
                high = mid -1;
            else
                return mid;
        }

        return -1;
    }
};

int main()
{
    Solution solve;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << solve.search(nums, target) << endl;


    return 0;
}
