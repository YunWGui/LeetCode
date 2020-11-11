/*
Title:
    31. Next Permutation
    31. 下一个排列
Description:
    实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
    如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
    必须原地修改，只允许使用额外常数空间。
    以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
Address: 
    https://leetcode-cn.com/problems/next-permutation/
*/


#include <iostream>
#include <vector>
#include <algorithm>  // next_permutation
using namespace std;

// 方法一：algorithm 库内置函数
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation( nums.begin(), nums.end() );
    }
};

// 方法二：
class Solution_2 {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while ( i >= 0 && nums[i] >= nums[i + 1] )
            --i;
        
        int j = nums.size() - 1;
        if ( i >= 0 ) {
            while ( j >= 0 && nums[j] <= nums[i] )
                --j;            
            swap( nums[i], nums[j] );
        }

        reverse( nums.begin() + i + 1, nums.end() );        
    }
};


int main()
{
    

    return 0;
}