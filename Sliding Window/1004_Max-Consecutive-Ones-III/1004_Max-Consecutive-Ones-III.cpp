/*
Title:
    1004. Max Consecutive Ones III
    1004. 最大连续1的个数 III
Address: 
    https://leetcode-cn.com/problems/max-consecutive-ones-iii/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：滑动窗口
// 思路：借鉴「424. 替换后的最长重复字符」的解题思路

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        if ( A.empty() || K < 0 )
            return 0;
        
        int maxLen = 0;
        int left = 0, right = 0;
        for ( ; right < (int)A.size(); ++right ) {
            if ( A[right] == 1 )
                ++maxLen;
            
            if ( right - left + 1 > maxLen + K ) {
                if ( A[left] == 1 )
                    --maxLen;
                ++left;
            }
        }

        return right - left;
    }
};

// 方法二：滑动窗口
class Solution_2 {
public:
    int longestOnes(vector<int>& A, int K) {
        int cnt = 0;  // 统计数组 A 中 0 的个数
        int ans = 0;
        
        int left = 0, right = 0;
        while ( right < (int)A.size() ) {
            if ( A[right] == 0 )
                ++cnt;
            
            while ( cnt > K ) {
                if ( A[left] == 0 )
                    --cnt;
                ++left;
            }

            ans = max( ans, right - left + 1 );
            ++right;
        }

        return ans;
    }
};

int main()
{
    

    return 0;
}