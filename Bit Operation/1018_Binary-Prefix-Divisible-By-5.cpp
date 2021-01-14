/*******************************************************************************
 * Title:
 *     1018. Binary Prefix Divisible By 5
 *     1018. 可被 5 整除的二进制前缀
 * Address: 
 *     https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/
 ******************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

// 方法二：对方法一的简化
class Solution_2 {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        vector<bool> ans( n );

        int number = ( A[0] == 0 ) ? 0 : 1;
        ans[0] = ( number == 0 ) ? true : false;

        for ( int i = 1; i < n; ++i ) {
            number = ( number * 2 + A[i] ) % 5;
            
            ans[i] = ( number == 0 ) ? true : false;
        }
        
        return ans;
    }
};


// 方法一：
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        vector<int> nums ( n );  // 用来记录第 i 位的结果

        nums[0] = ( A[0] == 0 ) ? 0 : 1;

        for ( int i = 1; i < n; ++i ) {
            // 如果 A[i] == 1，则第 i 位的结果是第 i - 1 位结果的 2 倍加 1
            // 如果 A[i] == 0，则第 i 位的结果是第 i - 1 位结果的 2
            nums[i] = ( nums[i - 1] * 2 + A[i] ) % 5;
        }

        vector<bool> ans( n );
        for ( int i = 0; i < n; ++i ) {
            ans[i] = ( nums[i] == 0 ) ? true : false;
        }
        
        return ans;
    }
};

int main()
{
    

    return 0;
}