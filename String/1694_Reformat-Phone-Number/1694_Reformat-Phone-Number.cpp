/*******************************************************************************
 * Title:
 *     1694. Reformat Phone Number
 *     1694. 重新格式化电话号码
 * Address: 
 *     https://leetcode-cn.com/problems/reformat-phone-number/submissions/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // isdigit
using namespace std;

// 方法一：模拟
class Solution {
public:
    string reformatNumber(string number) {
        int len = 0;
        for ( int i = 0; i < (int)number.size(); ++i ) {
            if ( number[i] == '-' || number[i] == ' ' )
                ;
            else 
                number[len++] = number[i];
        }
        
        number.resize( len );
        
        if ( len <= 3 )
            return number;
        
        if ( len % 3 != 0 ) {
            len -= 2;
            number.insert( len, "-" );
        }
        
        int i = 3;
        while ( i < len ) {
            number.insert( i, "-" );
            i += 4;
            len += 1;  // 因为新插入了"-"，所以「整体的长度」也 +1
        }
        
        return number;
    }
};

// 方法二：
// 参考：https://mp.weixin.qq.com/s/LXySnfQwN7ZfIlvNaLeYRQ
class Solution_2 {
public:
    string reformatNumber(string number) {
        string str;
        for ( char ch : number ) {
            // if ( '0' <= ch && ch <= '9' ) {  // 与下一行语义相同
            if ( isdigit( ch ) ) {
                str.push_back( ch );
            }
        }
        
        string ans;
        int cnt = 0;
        for ( int i = 0; i < (int)str.size(); ) {
            if ( ans.size() ) {
                ans += "-";
            }
            
            if ( i + 3 == (int)str.size() || i + 2 == (int)str.size() ) {
                ans += str.substr( i );
                break;
            }
            else if ( i + 4 == (int)str.size() ) {
                ans += str.substr( i, 2 );
                ans += "-";
                ans += str.substr( i + 2, 2 );
                break;
            }
            else {
                ans += str.substr( i, 3 );
                i += 3;
            }
        }
        
        return ans;
    }
};

int main()
{
    

    return 0;
}