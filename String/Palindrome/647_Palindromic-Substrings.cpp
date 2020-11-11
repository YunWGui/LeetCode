/*
Title:
    647. Palindromic Substrings
    647. 回文子串
Description:
    给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
    具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
Address:
    https://leetcode-cn.com/problems/palindromic-substrings/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 方法一：
class Solution {
public:
    int countSubstrings(string s) {
        if ( s.empty() )
            return 0;

        int count = 0;

        for ( int i = 0; i < (int)s.size(); ++i ) {
            // 迭代
            search_iter( s, i, i , count );
            search_iter( s, i, i + 1, count );
            
            // 递归
            // search_recu( s, i, i , count );
            // search_recu( s, i, i + 1, count );
        }

        return count;
    }

    // 迭代
    void search_iter( const string& s, int left, int right, int& count ) {
        while ( left >= 0 && right < (int)s.size() && s[left] == s[right] ) {
            ++count;
            --left; ++right;
        }
    }
    
    // 递归
    void search_recu( const string& s, int left, int right, int& count ) {
        if ( left < 0 || right >= (int)s.size() )  // 越界
            return;
        if ( s[left] != s[right] )  // 不相等
            return;

        ++count;

        search_recu( s, --left, ++right, count );
    }
};

int main()
{


    return 0;
}
