/*
Title:
    922. Sort Array By Parity II
    922. 按奇偶排序数组 II
Description:
    给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
    对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
    你可以返回任何满足上述条件的数组作为答案。
Address: 
    https://leetcode-cn.com/problems/sort-array-by-parity-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 方法一：
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int odd = 1, even = 0;

        while ( odd < n && even < n - 1 ) {
            while ( ( even < n - 1 ) && ( A[even] % 2 == 0 ) )
                even += 2;

            if ( even < n - 1 ) 
                while ( ( odd < n ) && ( A[odd] % 2 != 0 ) ) 
                    odd += 2;
            
            if ( odd < n && even < n - 1 ) {
                swap( A[odd], A[even] );
                odd += 2;
                even += 2;
            }
        }

        return A;
    }
};


// 方法二：
class Solution_2 {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd = 1;  // 奇数下标
        
        for ( int even = 0; even < (int)A.size(); even += 2 ) {
            if ( A[even] % 2 != 0 ) {
                while ( A[odd] % 2 != 0 )
                    odd += 2;
                
                swap( A[even], A[odd] );
            }
        }

        return A;
    }
};

int main()
{
    

    return 0;
}