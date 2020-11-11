/*
Title:
    171. Excel Sheet Column Number
    171. Excel表列序号
Address: 
    https://leetcode-cn.com/problems/excel-sheet-column-number/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    int titleToNumber(string s) {
        if ( s.empty() )
            return 0;
        
        int ans = 0;
        for ( char ch : s ) {
            ans = ans * 26 + ( ch - 'A' + 1 );
        }

        return ans;
    }
};

int main()
{
    

    return 0;
}