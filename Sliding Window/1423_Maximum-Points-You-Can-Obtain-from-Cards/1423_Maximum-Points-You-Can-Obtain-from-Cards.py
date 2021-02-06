"""
 * Title:
 *     1423. Maximum Points You Can Obtain from Cards
 *     1423. 可获得的最大点数
 * Address: 
 *     https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
"""

# 方法一：滑动窗口
class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        maxPoints = 0
        for i in range(k):
            maxPoints += cardPoints[i]
        
        sumPoints = maxPoints

        # [1, 2, 3, 4, 5, 6, 1], k = 3
        #  <--i           <--j  # i, j 移动方向，使得窗口大小始终是 k 
        
        i = k - 1  # 右边界一
        j = len(cardPoints) - 1  # 右边界二
        while i >= 0:
            sumPoints = sumPoints - cardPoints[i] + cardPoints[j]
            maxPoints = max(maxPoints, sumPoints)
            i -= 1
            j -= 1
        
        return maxPoints