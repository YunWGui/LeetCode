/*
Title:
    14. Longest Common Prefix
    14. 最长公共前缀
Description:
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
Address: 
    https://leetcode-cn.com/problems/longest-common-prefix/
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 方法一：纵向扫描
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if ( strs.empty() )
            return "";
        
        int len = strs[0].size();  // 第一个字符串的长度

        for ( int i = 0; i < len; ++i ) {
            char ch = strs[0][i];
            for ( int j = 1; j < (int)strs.size(); ++j ) {  // 遍历字符数组 strs
                if ( i == strs[j].size() || ch != strs[j][i] )  // 提前终止
                    return strs[0].substr( 0, i );
            }
        }

        return strs[0];
    }
};

// 方法二：
class Solution_2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) 
            return string();

        sort(strs.begin(), strs.end());

        string st = strs.front(), en = strs.back();

        int num = min(st.size(), en.size());

        int i;
        for(i = 0; i < num && st[i] == en[i]; ++i )
            ;

        return string(st, 0, i);
    }
};


int main()
{
    

    return 0;
}