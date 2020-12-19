"""
 * Title:
 *     290. Word Pattern
 *     290. 单词规律
 * Address: 
 *     https://leetcode-cn.com/problems/word-pattern/
"""

class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        dic = dict()
        ls = str.split(" ")
        
        if len(pattern) != len(ls):
            return False

        for ch, strr in zip(pattern, ls):  # dic[ch] = strr
            if ch in dic.keys():
                if dic[ch] != strr:
                    return False 
            else:  # ch not in dic
                if strr in dic.values():
                    return False
                dic[ch] = strr 
        
        return True


