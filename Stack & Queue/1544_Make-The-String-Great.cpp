/*
Title:
    1544. Make The String Great
    1544. 整理字符串
Address: 
    https://leetcode-cn.com/problems/make-the-string-great/
Tips:
    Weekly Contest 201
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 方法一：栈 - 用 string 模拟栈
class Solution {
public:
    string makeGood(string s) {
        string stack;
        for ( int i = 0; i < (int)s.size(); ++i ) {
            stack += s[i];
            int n = stack.size();
            if ( n >= 2 && ( stack[n - 1] + 32 == stack[n - 2] || stack[n - 1] - 32 == stack[n - 2] ) ) {
                stack.resize(n - 2);
            }
        }

        return stack;
    }
};

// 方法二：栈
class Solution_2 {
public:
    string makeGood(string s) {
        if ( s.size() <= 1 )
            return s;
        
        stack<char> stk;
        stk.push( s[0] );
        for ( int i = 1; i < (int)s.size(); ++i ) {
            if ( !stk.empty() && ( stk.top() + 32 == s[i] || stk.top() - 32 == s[i] ) )
                stk.pop();
            else
                stk.push( s[i] );
        }
        
        string res = "";
        while ( !stk.empty() ) {
            res += stk.top();  stk.pop();
        }

        reverse( res.begin(), res.end() );

        return res;
    }
};

int main()
{
    

    return 0;
}