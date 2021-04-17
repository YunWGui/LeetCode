"""
 * Title:
 *     49. Group Anagrams
 *     49. 字母异位词分组
 * Address:
 *     https://leetcode-cn.com/problems/group-anagrams/
"""

import collections

# 方法一：排序
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        record = collections.defaultdict(list)

        for sttr in strs:
            key = "".join(sorted(sttr))
            record[key].append(sttr)
        
        return list(record.values())
