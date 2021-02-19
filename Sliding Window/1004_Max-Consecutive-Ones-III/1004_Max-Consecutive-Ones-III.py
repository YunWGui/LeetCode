"""
Title:
    1004. Max Consecutive Ones III
    1004. 最大连续1的个数 III
Address: 
    https://leetcode-cn.com/problems/max-consecutive-ones-iii/
"""

# 方法一：滑动窗口
# 思路：借鉴「424. 替换后的最长重复字符」的解题思路
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        if len(A) == 0 or K < 0:
            return 0
        
        maxLen = 0
        left, right = 0, 0
        while right < len(A):
            if A[right] == 1:
                maxLen += 1
            
            if right - left + 1 > maxLen + K:
                if A[left] == 1:
                    maxLen -= 1
                left += 1
            
            right += 1

        return right - left


# 方法二：滑动窗口
class Solution_2:
    def longestOnes(self, A: List[int], K: int) -> int:
        cnt = 0  # 统计数组 A 中 0 的个数
        ans = 0

        left, right = 0, 0
        while right < len(A):
            if A[right] == 0:
                cnt += 1
            
            while cnt > K:
                if A[left] == 0:
                    cnt -= 1
                left += 1
            
            ans = max(ans, right - left + 1)
            right += 1
        
        return ans