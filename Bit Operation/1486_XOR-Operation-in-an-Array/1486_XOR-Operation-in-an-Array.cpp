/******************************************************************************
 * Title:
 *     1486. XOR Operation in an Array
 *     1486. 数组异或操作
 * Address:
 *     https://leetcode-cn.com/problems/xor-operation-in-an-array/
******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：异或
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        
        for ( int i = 0; i < n; ++i ) {
            ans ^= start + 2 * i;
        }            

        return ans;
    }
};


int main()
{
    

    return 0;
}