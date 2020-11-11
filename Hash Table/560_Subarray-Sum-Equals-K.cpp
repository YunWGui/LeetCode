/*
Title:
    560. Subarray Sum Equals K
    560. 和为K的子数组
Address: 
    https://leetcode-cn.com/problems/subarray-sum-equals-k/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 方法一：前缀和
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int curSum = 0;
        unordered_map<int, int> hash;
        
        for(int& num : nums){
            hash[curSum]++;
            curSum += num;
            cnt += hash[curSum - k];
        }
        
        return cnt;
    }
};

// 方法二：滑动窗口 - 暴力法 - 超时
class Solution_2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int windowSize = 1;
        int count = 0;

        while ( windowSize <= (int)nums.size() ) {
            int left = 0, right = 0;
            int curSum = 0;
            for ( ; right < windowSize; ++right )
                curSum += nums[right];
            
            if ( curSum == k )
                ++count;
            
            for ( ; right < (int) nums.size(); ++right ) {
                curSum += nums[right] - nums[left++];

                if ( curSum == k )
                    ++count;
            }

            ++windowSize;
        }

        return count;
    }
};

int main()
{
    

    return 0;
}