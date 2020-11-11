/*
Title:
    41. First Missing Positive
    41. 缺失的第一个正数
Address: 
    https://leetcode-cn.com/problems/first-missing-positive/
Tips:
    同《程序员代码面试指南》 8-25  P415
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    要找的数一定在区间[1, n + 1] 里
*/

// 方法二：原地哈希
// https://leetcode-cn.com/problems/first-missing-positive/solution/tong-pai-xu-python-dai-ma-by-liweiwei1419/
class Solution_2 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for ( int i = 0; i < n; ++i ) {
            while ( 1 <= nums[i] && nums[i] <= n && nums[nums[i] - 1] != nums[i] )
                swap( nums[nums[i] - 1], nums[i] );
        }

        for ( int i = 0; i < n; ++i )
            if ( nums[i] != i + 1 )
                return i + 1;
        
        return n + 1;
    }
};

// 方法一：原地哈希
// 要找的数一定在区间 [1, n + 1] 内
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int left = 0, right = nums.size();

        while ( left < right ) {
            if ( nums[left] == left + 1 )
                left++;
            else if ( nums[left] <= left || nums[left] > right || nums[nums[left] - 1] == nums[left] )
                nums[left] = nums[--right];
            else
                swap( nums[left], nums[nums[left] - 1] );
        }

        return left + 1;
    }
};

int main()
{
    

    return 0;
}