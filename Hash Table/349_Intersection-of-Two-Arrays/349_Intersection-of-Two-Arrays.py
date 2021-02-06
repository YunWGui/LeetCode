"""
 * Title:
 *     349. Intersection of Two Arrays
 *     349. 两个数组的交集
 * Address:
 *     https://leetcode-cn.com/problems/intersection-of-two-arrays/
"""

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        set1 = set(nums1)
        set2 = set(nums2)

        ans = list()
        for s1 in set1:
            if s1 in set2:
                ans.append(s1)
        
        return ans