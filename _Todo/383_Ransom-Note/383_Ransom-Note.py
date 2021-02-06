"""
 * Title:
 *     383. Ransom Note
 *     383. 赎金信
 * Address:
 *     https://leetcode-cn.com/problems/ransom-note/
"""

# 方法一：哈希表
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        record = dict()
        for ch in magazine:
            record.setdefault(ch, 0)
            record[ch] += 1
        
        for ch in ransomNote:
            if ch in record.keys():
                record[ch] -= 1
                if record[ch] < 0:
                    return False
            else:
                return False 
        
        return True