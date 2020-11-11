/*
Title:
    231. Power of Two
    231. 2的幂
Address: 
    https://leetcode-cn.com/problems/power-of-two/
*/


#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if ( n <= 0 )
            return false;
        if ( n == 1 )
            return true;
        if ( n & 1 )
            return false;
        
        while ( n > 1 ) {
            if ( n & 1 )
                return false;
            
            n /= 2;
        }

        return true;
    }
};

int main()
{
    

    return 0;
}