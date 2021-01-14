"""
 * Title:
 *     1018. Binary Prefix Divisible By 5
 *     1018. 可被 5 整除的二进制前缀
 * Address: 
 *     https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/
 """

class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        ans = list()
        number = 0

        for i in range(len(A)):
            number = (number * 2 + A[i]) % 5
            ans.append(number == 0)
        
        return ans