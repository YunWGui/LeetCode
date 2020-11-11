/*
Title:
    541. Reverse String II
    541. 反转字符串 II
Address: 
    https://leetcode-cn.com/problems/reverse-string-ii/
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int left = 0;
        int len = s.size();

        while ( left + 2 * k < len ) {
            reverse( s.begin() + left, s.begin() + left + k );
            left += 2 * k;
        }

        int delta = ( left + k <= len ) ? k : ( len - left );
        reverse( s.begin() + left, s.begin() + left + delta );

        return s;
    }
};


int main()
{
    

    return 0;
}