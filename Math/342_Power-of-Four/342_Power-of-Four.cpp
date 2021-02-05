/*******************************************************************************
 * Title:
 *     342. Power of Four
 *     342. 4的幂
 * Address: 
 *     https://leetcode-cn.com/problems/power-of-four/
 ******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    bool isPowerOfFour(int n) {
        if ( n <= 0 )
            return false;
        else if ( n == 1 )
            return true;
        else {  // n > 1
            long int temp = 1;
            while ( temp < n ) {
                temp *= 4;
            }            
            return temp == n;
        }
    }
};

// 方法二：
class Solution_2 {
public:
    bool isPowerOfFour(int n) {
        if ( n <= 0 )
            return false;
        else {  // n > 0 
            while ( n % 4 == 0 ) 
                n /= 4;
            
            return n == 1;
        }
    }
};

int main()
{
    

    return 0;
}