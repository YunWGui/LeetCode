"""
 * Title:
 *     219. Contains Duplicate II
 *     219. 存在重复元素 II
 * Address:
 *     https://leetcode-cn.com/problems/contains-duplicate-ii/
"""

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        record = set()
        for i in range(len(nums)):
            if nums[i] in record:
                return True
            
            record.add( nums[i] )
            if (len(record) > k):
                record.discard(nums[i - k])
        
        return False