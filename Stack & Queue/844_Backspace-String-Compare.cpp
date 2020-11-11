/*
Title:
    844. Backspace String Compare
    844. 比较含退格的字符串
Address: 
    https://leetcode-cn.com/problems/backspace-string-compare/
*/


#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string str1 = finalStr( S );
        string str2 = finalStr( T );

        return str1 == str2;
    }

    string finalStr( string& str ) {
        string ans;
        for ( int i = 0; i< (int)str.size(); ++i ) {
            if ( str[i] != '#' ) 
                ans.push_back( str[i] );
            else {  // str[i] == '#'
                if ( !ans.empty() )
                    ans.pop_back();
            }
        }

        return ans;
    }
};

int main()
{
    

    return 0;
}