/*******************************************************************************
 * Title:
 *     1696. Jump Game VI
 *     1696. 跳跃游戏 VI
 * Address: 
 *     https://leetcode-cn.com/problems/jump-game-vi/
 * Source:
 *     weekly-contest-220
 ******************************************************************************/

// 参考：https://mp.weixin.qq.com/s/LXySnfQwN7ZfIlvNaLeYRQ

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 方法一：花花酱 
// https://www.bilibili.com/video/BV1554y1t7Tz
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> dp( n );
        deque<int> DQ{ { 0 } };  // 双端队列
        dp[0] = nums[0];

        for ( int i = 1; i < n; ++i ) {
            dp[i] = nums[i] + dp[DQ.front()];
            while ( !DQ.empty() && dp[i] >= dp[DQ.back()] )
                DQ.pop_back();
            while ( !DQ.empty() && i - DQ.front() >= k )
                DQ.pop_front();
            DQ.push_back( i );
        }

        return dp[n - 1];        
    }
};


int main()
{
    

    return 0;
}