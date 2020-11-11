/*
Title:
    557. Reverse Words in a String III
    557. 反转字符串中的单词 III
Address: 
    https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0;
        
        while ( right < (int)s.size() ) {
            if ( s[right] == ' ' ) {
                reverse( s.begin() + left, s.begin() + right );
                left = right + 1;
            }              
            ++right;
        }

        reverse( s.begin() + left, s.end() );

        return s;
    }
};

// 方法二：
class Solution_2 {
public:
    string reverseWords(string s) {
        int left = 0, right = 0;
        
        while ( right < (int)s.size() ) {
            if ( s[right] == ' ' ) {
                reverseStr( s, left, right - 1 );
                left = right + 1;
            }
            ++right;
        }

        reverseStr( s, left, right - 1 );

        return s;
    }

    void reverseStr( string& str, int left, int right ) {  // [left, right]
        while ( left < right ) 
            swap( str[left++], str[right--] );
    }
};

int main()
{
    

    return 0;
}