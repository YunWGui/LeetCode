/*
Title:
    1248. Count Number of Nice Subarrays
    1248. 统计「优美子数组」
Address: 
    https://leetcode-cn.com/problems/count-number-of-nice-subarrays/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法二：前缀和
// https://mp.weixin.qq.com/s/FQ8HNU908iXzsDvMEd-utQ
class Solution_2 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> prefixCnt( nums.size() + 1 );  // 当前奇数的个数

        prefixCnt[0] = 1;

        int res = 0, cnt = 0;
        for ( int num : nums ) {
            cnt += ( num & 1 );
            prefixCnt[cnt]++;
            
            if ( cnt >= k )
                res += prefixCnt[cnt - k];
        }

        return res;
    }
};

// 方法一：滑动窗口
// https://mp.weixin.qq.com/s/FQ8HNU908iXzsDvMEd-utQ
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, oddCnt = 0, res = 0;

        while ( right < nums.size() ) {
            if ( nums[right++] & 1 )  // 统计「奇数」个数
                ++oddCnt;
            
            if ( oddCnt == k ) {
                int temp = right;

                // 先将滑动窗口的右边界向右拓展，直到出界或遇到下一个奇数
                while ( right < nums.size() && (nums[right] & 1) == 0 ) 
                    ++right;

                int rightEvenCnt = right - temp;  // rightEvenCnt 即为第 k 个奇数右边的偶数的个数

                int leftEvenCnt = 0;  // leftEvenCnt 即为第 1 个奇数左边的偶数的个数
                while ( ( nums[left] & 1 ) == 0 ) {
                    ++leftEvenCnt;
                    ++left;
                }

                res += ( 1 + leftEvenCnt ) * ( 1 + rightEvenCnt );
                ++left;
                --oddCnt;
            }
        }

        return res;
    }
};

int main()
{
    

    return 0;
}