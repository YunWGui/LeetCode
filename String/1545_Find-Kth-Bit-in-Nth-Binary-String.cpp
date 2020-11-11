/*
Title:
    1545. Find Kth Bit in Nth Binary String
    1545. 找出第 N 个二进制字符串中的第 K 位
Address: 
    https://leetcode-cn.com/problems/find-kth-bit-in-nth-binary-string/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 方法二:
// O(1) : https://mp.weixin.qq.com/s/AJPpAVxlZs3zbwHGn_Tvqw


// 方法一：暴力法
class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for ( int i = 2; i <= n; ++i ) {
            string temp = invert( s );
            reverse( temp.begin(), temp.end() );
            s = s + "1" + temp;
        }
        
        return s[k - 1];
    }
    
    string invert( string str ) {
        for ( int i = 0; i < (int)str.size(); ++i ) {
            if ( str[i] == '0' )
                str[i] = '1';
            else 
                str[i] = '0';
        }
        
        return str;
    }
};

int main()
{
    

    return 0;
}