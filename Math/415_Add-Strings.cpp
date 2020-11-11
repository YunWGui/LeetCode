/*
Title:
    415. Add Strings
    415. 字符串相加
Description:
    给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
Address: 
    https://leetcode-cn.com/problems/add-strings/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 方法二：
class Solution_2 {
public:
    string addStrings(string num1, string num2) {
        int r1 = num1.size() - 1, r2 = num2.size() - 1;
        int carry = 0;  // 进位标志

        string ans = "";

        while ( carry == 1 || r1 >= 0 || r2 >= 0 ) {
            int x = ( r1 < 0 ) ? 0 : num1[r1--] - '0';
            int y = ( r2 < 0 ) ? 0 : num2[r2--] - '0';

            ans.push_back( ( x + y + carry ) % 10 + '0' );

            carry = ( x + y + carry ) / 10;
        }

        reverse( ans.begin(), ans.end() );

        return ans;
    }
};

// 方法三：逻辑清晰、实操性强
/* 参考：Leetcode-67 */
class Solution_3 {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int n = max( n1, n2 );

        // 补位，让字符串 num1, num2 长度相同
        if ( n1 < n ) {
            string zero ( n - n1, '0' );
            num1 = zero + num1;
        }
        else {  //  n2 < n 
            string zero( n - n2, '0' );
            num2 = zero + num2;
        }
        
        string ans;
        int flag = 0;
        for ( int i = n - 1; i >= 0; --i ) {
            int sum = num1[i] - '0' + num2[i] - '0' + flag;
            
            ans.push_back( sum % 10 + '0' );
            flag = sum / 10;
        }

        if ( flag )
            ans.push_back( '1' );
        
        reverse( ans.begin(), ans.end() );
        
        return ans;
    }
};

// 方法一：模拟
class Solution {
public:
    string addStrings(string num1, string num2) {
        if ( num1.empty() || ( num1.size() == 1 && num1[0] == '0' ) )
            return num2;
        if ( num2.empty() || ( num2.size() == 1 && num2[0] == '0' ) )
            return num1;

        string ans;
        int r1 = num1.size() - 1;  // 左指针
        int r2 = num2.size() - 1;

        int flag = 0;  // 进位标志
        while ( r1 >= 0 && r2 >= 0 ) {
            int sum = num1[r1] - '0' + num2[r2] - '0';
            --r1; --r2;

            if ( sum + flag >= 10 ) {
                ans.push_back( sum + flag - 10 + '0' );
                flag = 1;
            }
            else {
                ans.push_back( sum + flag + '0' );
                flag = 0;
            }
        }

        while ( r1 >= 0 ) {
            if ( num1[r1] - '0' + flag >= 10 ) {
                ans.push_back( num1[r1] + flag - 10 );
                flag = 1;            
            }
            else {
                ans.push_back( num1[r1] + flag );
                flag = 0;
            }
            --r1;
        }

        while ( r2 >= 0 ) {
            if ( num2[r2] - '0' + flag >= 10 ) {
                ans.push_back( num2[r2] + flag - 10 );
                flag = 1;            
            }
            else {
                ans.push_back( num2[r2] + flag );
                flag = 0;
            }
            --r2;
        }

        if ( flag == 1 )
            ans.push_back( flag + '0' );

        reverse( ans.begin(), ans.end() );

        return ans;
    }
};

int main()
{
    // string str1 { "0" };
    // string str2 { "0" };
    string str1 { "0" };
    string str2 { "9133" };

    Solution solve;
    cout << solve.addStrings( str1, str2 );
    

    return 0;
}