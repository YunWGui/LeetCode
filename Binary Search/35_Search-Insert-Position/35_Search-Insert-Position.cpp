/*
Title:
    35. Search Insert Position
    35. 搜索插入位置
Description:
    Given a sorted array and a target value, return the index if the target is found.
    If not, return the index where it would be if it were inserted in order.

    You may assume no duplicates in the array.
Address:
    https://leetcode-cn.com/problems/search-insert-position/
*/


#include <iostream>
#include <vector>
using namespace std;


// 方法二：二分查找
class Solution_2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while ( left <= right ) {
            int mid = left + ( ( right - left ) >> 1 );
            if ( target < nums[mid] )
                right = mid - 1;
            else if ( nums[mid] < target )
                left = mid + 1;
            else
                return mid;
        }
        return left;
    }
};

// 方法一：顺序查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        for ( ; i < (int)nums.size(); ++i ) {
            if ( target <= nums[i] )
                break;
        }

        return i;
    }
};

int main()
{


    return 0;
}
