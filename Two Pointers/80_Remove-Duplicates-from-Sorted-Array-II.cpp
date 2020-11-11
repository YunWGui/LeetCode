/*
Title:
    80. Remove Duplicates from Sorted Array II
    80. 删除排序数组中的重复项 II
Address: 
    https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
*/


#include <iostream>
#include <vector>
using namespace std;

// 方法一：计数移位
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/solution/chang-gui-si-lu-jian-dan-ji-shu-yi-wei-dai-ma-jian/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int flag = 0, offset = 0;  // offset : 偏移量

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                flag++; // 计数
            else
                flag = 0; // 计数器置0

            if (flag >= 2)
                offset++; // 移位距离加1

            nums[i - offset] = nums[i]; // 移位
        }

        return n - offset;
    }
};

int main() { 
    vector<int> nums{ 1, 1, 1, 2, 2, 2 };
    Solution solve;
    cout << solve.removeDuplicates( nums );

    return 0; 
}