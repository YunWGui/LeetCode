/*
Title:
    324. Wiggle Sort II
    324. 摆动排序 II
Description:
    给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
Address: 
    https://leetcode-cn.com/problems/wiggle-sort-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：排序
/* 时间复杂度：O(nlogn)  空间复杂度：O(n) */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort( nums.begin(), nums.end() );

        int n = nums.size();
        int mid = n & 1 ? n / 2 : ( n / 2 - 1 );

        vector<int> arr( nums );

        int right = n - 1;
        for ( int i = 0; i < n; ++i ) {
            nums[i] = i & 1 ? arr[right--] : arr[mid--];
        }
    }
};

int main()
{
    

    return 0;
}