"""
 * Title:
 *     392. Is Subsequence
 *     392. 判断子序列
 * Address: 
 *     https://leetcode-cn.com/problems/is-subsequence/
"""

# 方法三：官方解法
# https://leetcode-cn.com/problems/is-subsequence/solution/pan-duan-zi-xu-lie-by-leetcode-solution/
class Solution_3:
    def isSubsequence(self, s: str, t: str) -> bool:
        lenS, lenT = len(s), len(t)
        i = j = 0

        while i < lenS and j < lenT:
            if s[i] == t[j]:
                i += 1
            j += 1
        
        return i == lenS

# 方法二：逻辑更清晰
class Solution_2:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0:
            return True
        elif len(t) == 0:  # 此时 len(s) != 0
            return False
        
        i = 0
        for j in range(len(t)):
            if s[i] == t[j]:
                i += 1
                if i == len(s):
                    return True
        
        return False

# 方法一：
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0:
            return True
        elif len(t) == 0:
            return False
        
        lenS = len(s)
        lenT = len(t)
        j = 0
        for i in range(lenS):
            while j < lenT:
                if s[i] == t[j]:
                    j += 1
                    break
                else:
                    j += 1
            
            if j == lenT and (i != lenS - 1 or s[-1] != t[-1]):
                return False
        
        return True

