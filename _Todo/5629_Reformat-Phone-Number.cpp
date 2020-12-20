/*******************************************************************************
 * Title:
 *     5629. Reformat Phone Number
 *     5629. 重新格式化电话号码
 * Address: 
 *     https://leetcode-cn.com/contest/weekly-contest-220/problems/reformat-phone-number/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
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

int main()
{
    

    return 0;
}