"""
 * Title:
 *     888. Fair Candy Swap
 *     888. 公平的糖果棒交换
 * Address: 
 *     https://leetcode-cn.com/problems/fair-candy-swap/
"""

class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        sumA, sumB = sum(A), sum(B)
        delta = (sumB - sumA) // 2  # sumB 与 sumA 相减的先后顺序，会影响到后续的 for 循环

        rec = set(B)
        ans = list()

        for a in A:
            b = a + delta
            if b in rec:
                ans = [a, b]
                break
        
        return ans
                