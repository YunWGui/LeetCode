/*******************************************************************************
 * Title:
 *     704. Binary Search
 *     704. 二分查找
 * Address:
 *     https://leetcode-cn.com/problems/binary-search/
 ******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;  
        
        int mid = 0;
        while ( left <= right ) {  // [left, right]
            mid = left + ( ( right - left ) >> 1 );
            if ( nums[mid] < target )
                left = mid + 1;
            else if ( target < nums[mid] )
                right = mid - 1;
            else  // target == nums[mid]
                return mid;
        }

        return -1;
    }
};

int main()
{
    

    return 0;
}