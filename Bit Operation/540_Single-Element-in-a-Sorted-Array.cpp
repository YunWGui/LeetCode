/*
Title:
    540. Single Element in a Sorted Array
    540. 有序数组中的单一元素
Address: 
    https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = nums[0];
        for ( int i = 1; i < (int)nums.size(); ++i ) {
            res ^= nums[i];
            if ( ( i & 1 ) && res != 0 )
                return res^nums[i];
        }

        return res;
    }
};

int main()
{
    

    return 0;
}