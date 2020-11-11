/*
Title:
    845. Longest Mountain in Array
    845. 数组中的最长山脉
Address: 
    https://leetcode-cn.com/problems/longest-mountain-in-array/
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：双指针
/*
时间复杂度：O( n^2 )
空间复杂度：O( 1 )
*/
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if ( A.size() < 3 )
            return 0;
        
        int ans = 0;
        const int N = A.size();

        for ( int i = 1; i < N - 1; ++i ) {
            if ( A[i - 1] < A[i] && A[i] > A[i + 1] ) {
                int left = i - 1, right = i + 1;
                while ( left >= 0 && A[left] < A[left + 1] )
                    --left;
                while ( right < N && A[right - 1] > A[right] )
                    ++right;
                
                ans = max( ans, right - left - 1 );
            }
        }

        return ans;
    }
};


int main()
{
    

    return 0;
}