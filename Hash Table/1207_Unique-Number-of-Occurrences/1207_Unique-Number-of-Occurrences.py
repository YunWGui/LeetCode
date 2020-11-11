"""
Title:
    1207. Unique Number of Occurrences
    1207. 独一无二的出现次数
Address: 
    https://leetcode-cn.com/problems/unique-number-of-occurrences/
"""

# 方法一：
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        M = dict()
        for i in arr:
            M.setdefault(i, 0)
            M[i] += 1
        
        return len(M.values()) == len(set(M.values()))
