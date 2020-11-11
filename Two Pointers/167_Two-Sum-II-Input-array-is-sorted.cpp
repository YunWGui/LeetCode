/*
Title:
    167. Two Sum II - Input array is sorted
    167. 两数之和 II - 输入有序数组
Address: 
    https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
*/


#include <iostream>
#include <vector>
using namespace std;

// 方法一：双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if ( numbers.empty() )
            return {};
        
        int left = 0, right = numbers.size() - 1;
        while ( left < right ) {
            if ( numbers[left] + numbers[right] < target )
                ++left;
            else if ( numbers[left] + numbers[right] > target )
                --right;
            else
                break;
        }

        return { left + 1, right + 1 };
    }
};


int main()
{
    

    return 0;
}