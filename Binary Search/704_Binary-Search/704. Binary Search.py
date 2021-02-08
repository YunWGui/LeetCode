"""
 * Title:
 *     704. Binary Search
 *     704. 二分查找
 * Address:
 *     https://leetcode-cn.com/problems/binary-search/
"""

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        while left <= right:  # [left, right]
            mid = (left + right) // 2  # // : 取整
            if nums[mid] < target:
                left = mid + 1
            elif target < nums[mid]:
                right = mid - 1
            else:  # target == nums[mid]
                return mid
        
        return -1