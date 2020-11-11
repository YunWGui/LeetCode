/*
Title:
    523. Continuous Subarray Sum
    523. 连续的子数组和
Address: 
    https://leetcode-cn.com/problems/continuous-subarray-sum/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 方法二：哈希表
class Solution_2 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if ( nums.size() <= 1 )
            return false;
        
        k = ( k == 0 ) ? INT_MAX : k;
        unordered_map<int, int> hash;
        
        int sum = 0;
        hash[0] = -1;
        for ( int i = 0; i < (int)nums.size(); ++i ) {
            sum += nums[i];
            if ( hash.find( sum % k ) != hash.end() ) {
                if ( i - hash[sum % k] > 1 )
                    return true;
            }
            else 
                hash[sum % k] = i;
        }
        
        return false;
    }
};

// 方法一：可扩展窗口大小的滑动窗口 - 暴力法
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int windowSize = 2;  // 滑窗大小
        
        while ( windowSize <= (int)nums.size() ) {
            int curSum = 0;
            int left = 0, right = 0;
            
            for ( ; right < windowSize; ++right )
                curSum += nums[right];
            
            if ( curSum == k || ( k != 0 && curSum % k == 0 ) )  // 存在极端样例，如：nums = [0, 0], k = 0
                return true;

            for ( ; right < (int)nums.size(); ++right ) {
                curSum += nums[right] - nums[left++];

                if ( curSum == k || ( k != 0 && curSum % k == 0 ) )
                    return true;
            }

            ++windowSize;
        }

        return false;
    }
};


int main()
{
    

    return 0;
}