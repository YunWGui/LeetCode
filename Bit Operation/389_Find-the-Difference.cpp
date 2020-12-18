/**
 * Title:
 *     389. Find the Difference
 *     389. 找不同
 * Address: 
 *     https://leetcode-cn.com/problems/find-the-difference/
 */


#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

// 方法二：位运算
/**
 * 思路：字符串 s + t 后，必然多余的那个字符的个数为「奇」数，其余为偶数
 *       而，两个相同的数「异或」时，其结果为 0
 */
class Solution_2 {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for ( int i = 0; i < (int)s.size(); ++i ) {
            ans ^= s[i];
            ans ^= t[i];
        }

        ans ^= t[s.size()];

        return ans;
    }
};

// 方法一：哈希表
/**
 * 根据题解：字符串 t 是在字符串 s 的基础上，多了一个「字母」。
 *           故，将两个字符同时放入 hash 表后，多出来的那个字母在 hash 表中的值为
 *          「奇」，其余字母为「偶」
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash[26];
        memset( hash, 0, sizeof(hash) );

        for ( char ch : s )  ++hash[ch - 'a'];
        for ( char ch : t )  ++hash[ch - 'a'];
        
        char ans;
        for ( int i = 0; i < 26; ++i ) 
            if ( hash[i] & 1 ) {
                ans = 'a' + i;
                break;
            }
                 
        return ans;
    }
};



int main()
{
    

    return 0;
}