"""
Title:
    27. Remove Element
    27. 移除元素
Description:
    Given an array nums and a value val, remove all instances of that value
    in-place and return the new length.
    Do not allocate extra space for another array, you must do this by modifying
    the input array in-place with O(1) extra memory.
    The order of elements can be changed. It doesn't matter what you leave
    beyond the new length.
Address:
    https://leetcode-cn.com/problems/remove-element/
"""

# 方法一：
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        
        return k

# 方法二：
class Solution_2:
    def removeElement(self, nums: List[int], val: int) -> int:
        left, right = 0, 0
        length = len(nums)

        while right < length:
            while right < length and nums[right] == val:
                right += 1
            if right < length:
                nums[left] = nums[right]
                left += 1
                right += 1
        
        return left