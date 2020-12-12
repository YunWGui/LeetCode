/*
Title:
    242. Valid Anagram
    242. 有效的字母异位词
Address: 
    https://leetcode-cn.com/problems/valid-anagram/
*/

#include <iostream>
#include <vector>
#include <string>
#include <string.h>  // memset
using namespace std;


// 方法二：
class Solution_2 {
public:
    bool isAnagram(string s, string t) {
        if ( s.size() != t.size() )
            return false;

        int nums[26];  // 英文字母有 26 个
        memset( nums, 0, sizeof( nums ) );

        for ( int i = 0; i < (int)s.size(); ++i ) {
            ++nums[s[i] - 'a'];
            --nums[t[i] - 'a'];
        }
        
        for ( int i = 0; i < 26; ++i )
            if ( nums[i] != 0 )
                return false;
            
        return true;
    }
};

// 方法一：
class Solution {
public:
    bool isAnagram(string s, string t) {
        int nums[26];  // 英文字母有 26 个
        memset( nums, 0, sizeof( nums ) );

        for ( char ch : s )
            ++nums[ch - 'a'];
        
        for ( char ch : t )
            --nums[ch - 'a'];
        
        for ( int i = 0; i < 26; ++i )
            if ( nums[i] != 0 )
                return false;
            
        return true;
    }
};

int main()
{
    

    return 0;
}