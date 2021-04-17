"""
 * Title:
 *     179. Largest Number
 *     179. 最大数
 * Address:
 *     https://leetcode-cn.com/problems/largest-number/
"""

import functools

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        strs = map(str, nums)  # 将「数字」映射为「字符串」

        def cmp(a, b):
            return 1 if a + b >= b + a else -1
        
        strs = sorted(strs, key=functools.cmp_to_key(cmp), reverse=True)
        
        return ''.join(strs) if strs[0] != '0' else '0'