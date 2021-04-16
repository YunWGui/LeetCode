"""
 * Title:
 *     217. Contains Duplicate
 *     217. 存在重复元素
 * Address:
 *     https://leetcode-cn.com/problems/contains-duplicate/
"""

# 方法一：哈希表/集合
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:

        return len(set(nums)) != len(nums)

# 方法二：排序
class Solution_2:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i - 1] == nums[i]:
                return True
        
        return False