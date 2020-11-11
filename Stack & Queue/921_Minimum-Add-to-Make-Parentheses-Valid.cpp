/*
Title:
    921. Minimum Add to Make Parentheses Valid
    921. 使括号有效的最少添加
Address: 
    https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 方法二：借助「栈」的思路
class Solution_2 {
public:
    int minAddToMakeValid(string S) {
        int nums = 0, ans = 0;

        for ( char ch : S ) {
            if ( ch == '(' )
                ++nums;
            else {
                --nums;  
                if ( nums == -1 ) {  // ')' 比 '(' 多一个
                    nums = 0;
                    ++ans; 
                }
            }
        }

        return ans + nums;  // nums : '(' 比 ')' 比 nums 个
    }
};

// 方法一：栈
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> stk;
        for ( char ch : S ) {
            if ( !stk.empty() && ( stk.top() == '(' && ch == ')' ) )
                stk.pop();
            else
                stk.push( ch );
        }

        return stk.size();
    }
};


int main()
{
    

    return 0;
}