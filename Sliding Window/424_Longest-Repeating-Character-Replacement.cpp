/*
Title:
    424. Longest Repeating Character Replacement
    424. 替换后的最长重复字符
Description:
    给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，
    总共可最多替换 k 次。
    在执行上述操作后，找到包含重复字母的最长子串的长度。
    
    注意:
        字符串长度 和 k 不会超过 10^4。
Address: 
    https://leetcode-cn.com/problems/longest-repeating-character-replacement/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 方法一：滑动窗口
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> M;
        int maxLen = 0;  // 重复字符的最长长度
        int left = 0, right = 0;
        for ( ; right < (int)s.size(); ++right ) {
            ++M[s[right]];
            maxLen = max( maxLen, M[s[right]] );

            if ( right - left + 1 > maxLen + k ) {  // 窗口滑动, maxLen + k : 替换后的最长长度
                --M[s[left]];
                ++left;
            }
        }
        
        return right - left;  // 返回窗口的大小 [left, right) <=> [left, s.size()]
    }
};

// 方法二:滑动窗口
class Solution_2 {
public:
    int characterReplacement(string s, int k) {
        if ( s.empty() || k < 0 )
            return 0;
        
        int maxLen = 0;
        int hashMap[128] = {0};
        int left = 0, right = 0;
        for ( ; right < (int)s.size(); ++right ) {
            ++hashMap[s[right]];
            maxLen = max( maxLen, hashMap[s[right]] );

            if ( right - left + 1 > maxLen + k ) {
                --hashMap[s[left]];
                ++left;
            }
        }

        return right - left;

    }
};

int main()
{
    

    return 0;
}