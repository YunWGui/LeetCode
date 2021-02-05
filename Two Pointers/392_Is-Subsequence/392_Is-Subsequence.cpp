/*******************************************************************************
 * Title:
 *     392. Is Subsequence
 *     392. 判断子序列
 * Address: 
 *     https://leetcode-cn.com/problems/is-subsequence/
 ******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// 方法三：官方解法
// https://leetcode-cn.com/problems/is-subsequence/solution/pan-duan-zi-xu-lie-by-leetcode-solution/
class Solution_3 {
public:
    bool isSubsequence(string s, string t) {
        int lenS = s.size(), lenT = t.size();
        int i = 0, j = 0;

        while ( i < lenS && j < lenT ) {
            if ( s[i] == t[j] )
                ++i;
            ++j;
        }

        return i == lenS;
    }
};

// 方法二：逻辑更清晰
class Solution_2 {
public:
    bool isSubsequence(string s, string t) {
        if ( s.empty() )
            return true;
        else if ( t.empty() )
            return false;
        
        int i = 0, j = 0;

        for ( int j = 0; j < (int)t.size(); ++j ) {
            if ( s[i] == t[j] ) {
                ++i;
                if ( i == (int)s.size() )
                    return true;
            }
        }

        return false;
    }
};


// 方法一：
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if ( s.empty() )
            return true;
        else if ( t.empty() )  // 此时 s 
            return false;

        int lenS = s.size(), lenT = t.size();
        int i = 0, j = 0;

        for ( i = 0; i < lenS; ++i ) {
            while ( j < lenT ) {
                if ( s[i] == t[j++] ) {  // 进入 if 语句后，会执行 j++
                    break;
                }
            }

            // j == lenT : 此时遍历到 t 末端
            if ( j == lenT && ( i != lenS - 1 || s.back() != t.back() ) ) {
                return false;
            }
        }

        return true;
    }
};



int main()
{
    

    return 0;
}