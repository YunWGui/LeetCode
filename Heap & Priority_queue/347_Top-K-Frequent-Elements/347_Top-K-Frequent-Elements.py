"""
Title:
    347. Top K Frequent Elements
    347. 前 K 个高频元素
Address: 
    https://leetcode-cn.com/problems/top-k-frequent-elements/
"""

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dic = dict()
        for num in nums:
            dic.setdefault(num, 0)
            dic[num] += 1
        
        listTuple = []
        for i in dic.items():
            listTuple.append(i)
        
        listTuple.sort(key=lambda x: x[1], reverse=True)

        res = []
        for i in range(k):
            res.append(listTuple[i][0])
        
        return res
