# !/usr/bin/env python 
# -*- coding:utf-8 -*-
"""
Created on Thu Sep 26 21:19:51 2019

@author: SHI YI
"""

"""
Title;
	26. Remove Duplicates from Sorted Array
	26. 删除排序数组的重复项
Address:
	https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
"""

# 方法一：
class Solution:
    def removeDuplicates(self, nums):
        return list(set(nums))      

# 方法二：双指针
class Solution_2:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return len(nums)
        
        left, right = 0, 1 
        length = len(nums)

        while right < length:
            while right < length and nums[left] == nums[right]:
                right += 1
            
            if right >= length:
                break
            
            left += 1
            nums[left] = nums[right]
            right += 1
        
        return left + 1


#arr =  [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
arr = [1, 2, 2]
solve = Solution()
x = solve.removeDuplicates(arr)
print(x)