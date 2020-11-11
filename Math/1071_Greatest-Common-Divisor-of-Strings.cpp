/*
Title:
    1071. Greatest Common Divisor of Strings
    1071. 字符串的最大公因子
Address:
    https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// 方法二：
class Solution_2 {
public:
    string gcdOfStrings(string str1, string str2) {
        if ( str1 + str2 != str2 + str1 )
            return "";
        
        int maxLen = gcd( str1.size(), str2.size() );

        return str1.substr( 0, maxLen );
    }

    int gcd( int a, int b ) {
        return a % b == 0 ? b : gcd( b, a % b );
    }
};

// 方法一：数学
// 参考：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/zi-fu-chuan-de-zui-da-gong-yin-zi-by-leetcode-solu/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if ( str1 + str2 != str2 + str1 )
            return "";

        // 辗转相除法求 gcd
        return str1.substr(0, gcd( str1.size(), str2.size() ) );
    }
    int gcd(int a, int b ) {
        // return b == 0 ? a : gcd( b, a % b );
        if ( b == 0 )
            return a;
        else 
            return gcd( b, a % b );
    }
};

int main()
{
    

    return 0;
}