"""
 * Title:
 *     1694. Reformat Phone Number
 *     1694. 重新格式化电话号码
 * Address: 
 *     https://leetcode-cn.com/problems/reformat-phone-number/submissions/
"""

class Solution:
    def reformatNumber(self, number: str) -> str:
        ans = str()
        ans = number.replace("-", "").replace(" ", "")

        n = len(ans)
        if n <= 3:
            return ans 
        
        if n % 3 != 0:
            n -= 2
            ans = ans[:n] + '-' + ans[n:]
        
        idx = 3
        while idx < n:
            ans = ans[:idx] + '-' + ans[idx:]
            idx += 4
            n += 1
        
        return ans


if __name__ == '__main__':
    number = "1-23-45 6"
    solve = Solution()
    ans = solve.reformatNumber( number )
    print( ans )