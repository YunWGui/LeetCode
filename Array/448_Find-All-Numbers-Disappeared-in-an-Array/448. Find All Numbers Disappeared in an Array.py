"""
 * Title:
 *     448. Find All Numbers Disappeared in an Array
 *     448. 找到所有数组中消失的数字
 * Address:
 *     https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
"""

# 方法一：
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        nums.append( 0 )

        for i in range(len(nums)):
            while nums[i] != i:
                if nums[i] == nums[nums[i]]:
                    break
                # nums[i], nums[nums[i]] = nums[nums[i]], nums[i]  --> Error
                temp = nums[i]
                nums[i] = nums[nums[i]]
                nums[temp] = temp

        ans = list()
        for i in range(len(nums)):
            if nums[i] != i:
                ans.append(i)
        
        return ans

# 方法二：
class Solution_2:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        nums.append( 0 )
        n = len(nums)
    
        for num in nums:
            nums[num % n] += n 
        
        ans = list()
        for i in range(n):
            if nums[i] < n:
                ans.append(i)
        
        return ans