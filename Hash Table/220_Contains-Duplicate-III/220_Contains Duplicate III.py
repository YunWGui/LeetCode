"""
 * Title:
 *     220. Contains Duplicate III
 *     220. 存在重复元素 III
 * Address:
 *     https://leetcode-cn.com/problems/contains-duplicate-iii/
"""

import bisect

# https://leetcode-cn.com/problems/contains-duplicate-iii/solution/fu-xue-ming-zhu-hua-dong-chuang-kou-mo-b-jnze/
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        from sortedcontainers import SortedSet
  
        record = SortedSet()
        left, right = 0, 0
  
        while right < len(nums):
            if right - left > k:
                record.remove(nums[left])
                left += 1
         
            index = bisect.bisect_left(record, nums[right] - t)
         
            if record and index >= 0 and index < len(record) and abs(record[index] - nums[right]) <= t:
                return True
         
            record.add(nums[right])
            right += 1
  
        return False
