"""
Title:
    122. Best Time to Buy and Sell Stock II
    122. 买卖股票的最佳时机 II
Address: 
    https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
"""

# 方法一：贪心
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        total_gain = 0

        for i in range(1, len(prices)):
            if prices[i - 1] < prices[i]:
                total_gain += prices[i] - prices[i - 1]
        
        return total_gain