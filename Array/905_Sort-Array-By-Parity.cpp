/*
Title:
    905. Sort Array By Parity
    905. 按奇偶排序数组
Description:
    给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
    你可以返回满足此条件的任何数组作为答案。
Address: 
    https://leetcode-cn.com/problems/sort-array-by-parity/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 方法二：
class Solution_2 {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0;
        
        for ( int right = 0; right < (int)A.size(); ++right ) 
            if ( A[right] % 2 == 0 )
                swap( A[right], A[left++] );

        return A;
    }
};

// 方法一：双指针
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0, right = A.size() - 1;

        while ( left < right ) {
            while ( left < right && A[left] % 2 == 0 )
                ++left;
            
            while ( left < right && A[right] % 2 == 1 ) 
                --right;

            if ( left < right )
                swap( A[left++], A[right--] );
        }

        return A;
    }
};


int main()
{
    

    return 0;
}