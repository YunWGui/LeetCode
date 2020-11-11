/*
Title:
    75. Sort Colors
    75. 颜色分类
Address: 
    https://leetcode-cn.com/problems/sort-colors/
Tips:
    荷兰国旗问题
*/


#include <iostream>
#include <vector>
using namespace std;

// 方法一：双指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int curIdx = 0;
        
        while ( curIdx <= right ) {
            if ( nums[curIdx] == 0 ) {
                swap( nums[left++], nums[curIdx++] );
            }
            else if ( nums[curIdx] == 1 ) {
                ++curIdx;
            }
            else {  // nums[curIdx] == 2
                swap( nums[curIdx], nums[right--] );
            }
        }
    }
};

int main()
{
    

    return 0;
}